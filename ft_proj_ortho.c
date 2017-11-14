/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proj_ortho.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 09:10:51 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/24 11:59:29 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "ft_printf/ft_printf.h"

t_env	*ft_proj_ortho(t_env *env)
{
	t_parse	*tmp1;
	t_parse	*tmp2;
	int		y;
	int		nc;

	tmp1 = env->map;
	y = 0;
	nc = tmp1->cn;
	tmp1 = ft_operations(env, tmp1, y);
	y++;
	tmp2 = tmp1;
	tmp1 = tmp1->next;
	while (tmp1 != NULL)
	{
		tmp1 = ft_operations(env, tmp1, y);
		y++;
		ft_proj_print(env, tmp2, tmp1, nc);
		tmp2 = ft_lstrealloc(env, tmp2);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	ft_single_proj(env, tmp2, nc);
	tmp2 = ft_lstrealloc(env, tmp2);
	return (env);
}

t_parse	*ft_operations(t_env *env, t_parse *tmp, int y)
{
	int		x;
	int		nc;
	float	om;
	float	al;

	x = 0;
	nc = tmp->cn;
	om = env->om;
	al = env->al;
	while (x < nc)
	{
		tmp->prox[x] = env->bx + env->fac * (cos(om) * x + sin(om) * y);
		tmp->proy[x] = env->by + env->fac * (cos(al) * \
			(sin(om) * x - cos(om) * y)) + cos(al) * tmp->line[x] * env->fac;
		x++;
	}
	return (tmp);
}

void	ft_proj_print(t_env *env, t_parse *tmp1, t_parse *tmp2, int nc)
{
	int	i;

	i = 0;
	while (i + 1 < nc)
	{
		if (env->seg)
			free(env->seg);
		env->seg = ft_seg_init(tmp1->prox[i], tmp1->proy[i],\
			tmp1->prox[i + 1], tmp1->proy[i + 1]);
		ft_drawseg(env);
		if (env->seg)
			free(env->seg);
		env->seg = ft_seg_init(tmp1->prox[i], tmp1->proy[i],\
			tmp2->prox[i], tmp2->proy[i]);
		ft_drawseg(env);
		i++;
	}
	if (env->seg)
		free(env->seg);
	env->seg = ft_seg_init(tmp1->prox[i], tmp1->proy[i],\
		tmp2->prox[i], tmp2->proy[i]);
	ft_drawseg(env);
}

void	ft_single_proj(t_env *env, t_parse *tmp1, int nc)
{
	int	i;

	i = 0;
	while (i + 1 < nc)
	{
		if (env->seg)
			free(env->seg);
		env->seg = ft_seg_init(tmp1->prox[i], tmp1->proy[i],\
			tmp1->prox[i + 1], tmp1->proy[i + 1]);
		ft_drawseg(env);
		i++;
	}
}

t_seg	*ft_seg_init(int x0, int y0, int x1, int y1)
{
	t_seg	*tmp;

	tmp = (t_seg*)malloc(sizeof(t_seg));
	if (!tmp)
		exit(0);
	tmp->x0 = x0;
	tmp->x1 = x1;
	tmp->y0 = y0;
	tmp->y1 = y1;
	return (tmp);
}
