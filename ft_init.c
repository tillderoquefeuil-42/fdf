/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:27:23 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/25 13:48:05 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "ft_printf/ft_printf.h"

t_env	*ft_struct_init(int winx, int winy, char *winname)
{
	t_env	*env;

	env = (t_env*)malloc(sizeof(t_env));
	if (!env)
		ft_outfdf(1, env);
	env->seg = (t_seg*)malloc(sizeof(t_seg));
	if (!env->seg)
		ft_outfdf(1, env);
	env->winx = winx;
	env->winy = winy;
	env->map = NULL;
	env->mlx = mlx_init(1, env);
	if (!env->mlx)
		ft_outfdf(1, env);
	env->win = mlx_new_window(env->mlx, winx, winy, winname);
	if (!env->win)
		ft_outfdf(1, env);
	env->color = 0x00FFFFFF;
	env->bx = 0;
	env->by = 0;
	env->fac = 15;
	env->om = 5.7;
	env->al = 4.1;
	return (env);
}

void	ft_outfdf(int nb, t_env *env)
{
	if (nb == 1)
		ft_printf("Malloc Failed\n");
	if (nb == 2)
		ft_printf("Map Error\n");
	if (nb == 3)
		ft_printf("Empty map\n");
	env = ft_clearenv(env);
	ft_printf("END OF FDF\n");
	exit(0);
}

t_env	*ft_clearenv(t_env *env)
{
	if (env->mlx)
	{
		free(env->mlx);
		env->mlx = NULL;
	}
	if (env->win)
	{
		free(env->win);
		env->win = NULL;
	}
	if (env->seg)
	{
		free(env->seg);
		env->seg = NULL;
	}
	env->map = ft_clearmap(env);
	if (env)
		free(env);
	return (NULL);
}

t_parse	*ft_clearmap(t_env *env)
{
	t_parse	*tmp;
	t_parse	*tmp2;

	tmp = env->map;
	while (tmp != NULL)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		if (tmp2)
		{
			if (tmp2->line)
				free(tmp2->line);
			if (tmp2->prox)
				free(tmp2->prox);
			if (tmp2->proy)
				free(tmp2->proy);
			tmp2->line = NULL;
			tmp2->prox = NULL;
			tmp2->proy = NULL;
			free(tmp2);
			tmp2 = NULL;
		}
	}
	return (NULL);
}
