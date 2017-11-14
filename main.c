/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:25:16 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/24 11:32:08 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "ft_printf/ft_printf.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 2)
	{
		ft_printf("BEGIN OF FDF\n");
		env = ft_struct_init(1000, 1000, "_FDF_");
		env = ft_parsing(env, argv[1]);
		ft_printf("\nUse directional keys to move in 2D.\n");
		ft_printf("Use numeric pad keys to move in 3D.\n");
		ft_printf("Use '+' and '-' to zoom and dezoom.\n\n");
		env = ft_proj_ortho(env);
		mlx_key_hook(env->win, *ft_key_hook, env);
		mlx_mouse_hook(env->win, *ft_mouse_hook, env);
		mlx_loop(env->mlx);
	}
	else
		ft_printf("use : ./mlx file.fdf\n");
	return (0);
}
