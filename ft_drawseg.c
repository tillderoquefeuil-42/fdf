/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawseg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:02:06 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/24 11:12:26 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "ft_printf/ft_printf.h"

int		ft_drawseg(t_env *env)
{
	int	x;
	int	y;

	if (env->seg->y0 > env->seg->y1)
	{
		y = env->seg->y0;
		x = env->seg->x0;
		env->seg->y0 = env->seg->y1;
		env->seg->x0 = env->seg->x1;
		env->seg->y1 = y;
		env->seg->x1 = x;
	}
	if (env->seg->x1 >= env->seg->x0)
	{
		env = ft_firstseg(env);
		env = ft_firstdrawing(env);
	}
	else
	{
		env = ft_secondseg(env);
		env = ft_seconddrawing(env);
	}
	return (0);
}

t_env	*ft_firstseg(t_env *env)
{
	env->seg->dx = env->seg->x1 - env->seg->x0;
	env->seg->dy = env->seg->y1 - env->seg->y0;
	if (env->seg->dx >= env->seg->dy)
	{
		env->seg->dp = 2 * env->seg->dy - env->seg->dx;
		env->seg->de = 2 * env->seg->dy;
		env->seg->dne = 2 * (env->seg->dy - env->seg->dx);
		env->seg->cas = 0;
	}
	else
	{
		env->seg->dp = 2 * env->seg->dx - env->seg->dy;
		env->seg->de = 2 * env->seg->dx;
		env->seg->dne = 2 * (env->seg->dx - env->seg->dy);
		env->seg->cas = 1;
	}
	return (env);
}

t_env	*ft_secondseg(t_env *env)
{
	env->seg->dx = env->seg->x0 - env->seg->x1;
	env->seg->dy = env->seg->y1 - env->seg->y0;
	if (env->seg->dx >= env->seg->dy)
	{
		env->seg->dp = 2 * env->seg->dy - env->seg->dx;
		env->seg->de = 2 * env->seg->dy;
		env->seg->dne = 2 * (env->seg->dy - env->seg->dx);
		env->seg->cas = 2;
	}
	else
	{
		env->seg->dp = 2 * env->seg->dx - env->seg->dy;
		env->seg->de = 2 * env->seg->dx;
		env->seg->dne = 2 * (env->seg->dx - env->seg->dy);
		env->seg->cas = 3;
	}
	return (env);
}

t_env	*ft_firstdrawing(t_env *env)
{
	int	x;
	int	y;

	x = env->seg->x0;
	y = env->seg->y0;
	mlx_pixel_put(env->mlx, env->win, x, y, env->color);
	while (x < env->seg->x1 || y != env->seg->y1)
	{
		if (env->seg->dp <= 0)
			env->seg->dp = env->seg->dp + env->seg->de;
		else
		{
			env->seg->dp = env->seg->dp + env->seg->dne;
			if (env->seg->cas == 0)
				y++;
			else
				x++;
		}
		if (env->seg->cas == 0)
			x++;
		else
			y++;
		mlx_pixel_put(env->mlx, env->win, x, y, env->color);
	}
	return (env);
}

t_env	*ft_seconddrawing(t_env *env)
{
	int	x;
	int	y;

	x = env->seg->x0;
	y = env->seg->y0;
	mlx_pixel_put(env->mlx, env->win, x, y, env->color);
	while (x > env->seg->x1 || y != env->seg->y1)
	{
		if (env->seg->dp <= 0)
			env->seg->dp = env->seg->dp + env->seg->de;
		else
		{
			env->seg->dp = env->seg->dp + env->seg->dne;
			if (env->seg->cas == 2)
				y++;
			else
				x--;
		}
		if (env->seg->cas == 2)
			x--;
		else
			y++;
		mlx_pixel_put(env->mlx, env->win, x, y, env->color);
	}
	return (env);
}
