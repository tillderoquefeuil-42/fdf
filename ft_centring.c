/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_centring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 09:10:51 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/29 09:55:05 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "ft_printf/ft_printf.h"

t_env	*ft_centring(t_env *env)
{
	t_parse	*tmp1;
	t_parse	*tmp2;
	int		y;
	int		nc;

	tmp1 = env->map;
	y = 0;
	env->ctr[0] = env->winx;
	env->ctr[1] = 0;
	env->ctr[2] = env->winy;
	env->ctr[3] = 0;
	nc = tmp1->cn;
	tmp1 = ft_op_ctr(env, tmp1, y);
	tmp2 = tmp1;
	tmp1 = tmp1->next;
	while (tmp1 != NULL && ++y > 0)
	{
		tmp1 = ft_op_ctr(env, tmp1, y);
		tmp2 = ft_lstrealloc(env, tmp2);
		tmp2 = tmp1;
		tmp1 = tmp1->next;
	}
	tmp2 = ft_lstrealloc(env, tmp2);
	env = ft_fin_ctr(env);
	return (env);
}

t_parse	*ft_op_ctr(t_env *env, t_parse *tmp, int y)
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
		tmp->prox[x] = env->fac * (cos(om) * x + sin(om) * y);
		tmp->proy[x] = env->fac * (cos(al) * (sin(om) * x - cos(om) * y))\
			+ cos(al) * tmp->line[x] * env->fac;
		env = ft_cmp_ctr(env, tmp->prox[x], tmp->proy[x]);
		x++;
	}
	return (tmp);
}

t_env	*ft_cmp_ctr(t_env *env, int x, int y)
{
	if (x < env->ctr[0])
		env->ctr[0] = x;
	if (x > env->ctr[1])
		env->ctr[1] = x;
	if (y < env->ctr[2])
		env->ctr[2] = y;
	if (y > env->ctr[3])
		env->ctr[3] = y;
	return (env);
}

t_env	*ft_fin_ctr(t_env *env)
{
	env->bx = env->winx / 2 - (env->ctr[1] - env->ctr[0]) / 2 - env->ctr[0];
	env->by = env->winy / 2 - (env->ctr[3] - env->ctr[2]) / 2;
	env->ctr[0] = env->bx;
	env->ctr[1] = env->by;
	return (env);
}
