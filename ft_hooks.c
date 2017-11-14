/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:52:04 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/25 13:49:07 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "ft_printf/ft_printf.h"

int		ft_key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		ft_outfdf(0, env);
	env = ft_rotate(keycode, env);
	env = ft_keycode(keycode, env);
	env = ft_color(keycode, env);
	return (0);
}

int		ft_mouse_hook(int button, int mx, int my, t_env *env)
{
	static int		n = 0;

	if (mx < 0 || my < 0 || mx > env->winx || my > env->winy)
		return (0);
	if (button || env)
		mlx_pixel_put(env->mlx, env->win, mx, my, 0x00FFFFFF);
	if (n % 2 == 0)
	{
		env->seg->x0 = mx;
		env->seg->y0 = my;
	}
	else
	{
		env->seg->x1 = mx;
		env->seg->y1 = my;
		ft_drawseg(env);
	}
	n++;
	return (0);
}

t_env	*ft_rotate(int key, t_env *env)
{
	if (key == 86 || key == 91 || key == 88 || key == 84)
	{
		mlx_clear_window(env->mlx, env->win);
		if (key == 86)
			env->om = env->om - 0.1;
		else if (key == 91)
			env->al = env->al - 0.1;
		else if (key == 88)
			env->om = env->om + 0.1;
		else if (key == 84)
			env->al = env->al + 0.1;
		env = ft_proj_ortho(env);
	}
	else if (key == 49 || key == 87)
	{
		mlx_clear_window(env->mlx, env->win);
		env->fac = 15;
		env->color = 0x00FFFFFF;
		env->om = 5.7;
		env->al = 4.1;
		env->bx = env->ctr[0];
		env->by = env->ctr[1];
		env = ft_proj_ortho(env);
	}
	return (env);
}

t_env	*ft_keycode(int key, t_env *env)
{
	if (key == 76 || key == 69 || key == 78 ||\
		(122 < key && key < 127) || key == 24 || key == 27)
	{
		mlx_clear_window(env->mlx, env->win);
		if (key == 69 || key == 24)
			env->fac = env->fac + 1;
		else if (key == 78 || key == 27)
			env->fac = env->fac - 1;
		else if (key == 123)
			env->bx = env->bx - 5;
		else if (key == 124)
			env->bx = env->bx + 5;
		else if (key == 125)
			env->by = env->by + 5;
		else if (key == 126)
			env->by = env->by - 5;
		if (key != 76)
			env = ft_proj_ortho(env);
	}
	return (env);
}

t_env	*ft_color(int k, t_env *env)
{
	if (17 < k && k < 24)
	{
		mlx_clear_window(env->mlx, env->win);
		if (k == 18)
			env->color = 0x0000FFFF;
		else if (k == 19)
			env->color = 0x00FF00FF;
		else if (k == 20)
			env->color = 0x00FFFF00;
		else if (k == 21)
			env->color = 0x000000FF;
		else if (k == 23)
			env->color = 0x00FF0000;
		else if (k == 22)
			env->color = 0x0000FF00;
		env = ft_proj_ortho(env);
	}
	return (env);
}
