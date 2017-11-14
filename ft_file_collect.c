/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_collect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 10:40:17 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/24 13:42:07 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "ft_printf/ft_printf.h"
#include "get_next_line.h"

int		ft_open_file(char *s)
{
	int	fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		write(2, "open error\n", 11);
		ft_printf("use : ./mlx file.fdf\n");
		exit(0);
	}
	return (fd);
}

int		ft_check_line(char *str, int nc, t_env *env)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] != 0)
	{
		while (str[i] == 32)
			i++;
		if (str[i] == 43 || str[i] == 45)
			i++;
		while (47 < str[i] && str[i] < 58)
			i++;
		if (str[i] == 0 || str[i] == 32 || str[i] == '\n')
		{
			c++;
			while (str[i] == 32)
				i++;
		}
		else
			ft_outfdf(2, env);
	}
	if (nc > 0 && nc != c)
		ft_outfdf(2, env);
	return (c);
}

int		*ft_add_tab(char *str, int nc, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nc)
	{
		tab[i] = ft_atoi(str + j);
		i++;
		while (str[j] == 32)
			j++;
		while (str[j] != 32 && str[j] != 0)
			j++;
	}
	return (tab);
}

t_env	*ft_parsing(t_env *env, char *s)
{
	int		fd;
	int		nc;
	char	*str;
	t_parse	*begin;
	t_parse	*tmp;

	fd = ft_open_file(s);
	begin = NULL;
	if (get_next_line(fd, &str) < 1)
		ft_outfdf(3, env);
	nc = ft_check_line(str, 0, env);
	tmp = ft_lstnew(nc, env);
	tmp->line = ft_add_tab(str, nc, tmp->line);
	ft_lstadd(&begin, tmp);
	while (get_next_line(fd, &str) > 0)
	{
		nc = ft_check_line(str, nc, env);
		tmp = ft_lstnew(nc, env);
		tmp->line = ft_add_tab(str, nc, tmp->line);
		ft_lstadd(&begin, tmp);
	}
	env->map = begin;
	env = ft_centring(env);
	return (env);
}
