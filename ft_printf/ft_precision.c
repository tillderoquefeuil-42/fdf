/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 11:52:34 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:54:14 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putprecision(t_print **sprt, char *str)
{
	int		c;
	char	*s;
	int		i;

	i = 0;
	c = ft_strlen(str);
	s = ft_strnew((*sprt)->p);
	if (str[0] == '-')
		(*sprt)->p = (*sprt)->p + 1;
	if ((*sprt)->p == 0 || ((*sprt)->p <= c && (*sprt)->s[(*sprt)->pos]
		!= 's') || ((*sprt)->p >= c && (*sprt)->s[(*sprt)->pos] == 's'))
	{
		ft_strdel(&s);
		return (str);
	}
	if ((*sprt)->p < c && (*sprt)->p > 0)
		s = ft_strncpy(s, str, (*sprt)->p);
	else if ((*sprt)->p > c && (*sprt)->p > 0)
	{
		while (c++ < (*sprt)->p)
			s[i++] = 48;
		s = ft_strcat(s, str);
	}
	ft_strdel(&str);
	return (s);
}

int		ft_precision(t_print **sprt)
{
	char	*str;
	int		j;

	(*sprt)->pos++;
	j = (*sprt)->pos;
	while (47 < (*sprt)->s[j] && (*sprt)->s[j] < 58)
		j++;
	str = ft_strsub((*sprt)->s, (*sprt)->pos, j - (*sprt)->pos);
	(*sprt)->pos = j;
	j = ft_atoi(str);
	ft_strdel(&str);
	if (j == 0)
		return (ft_nullprecision(sprt));
	(*sprt)->p = j;
	return ((*sprt)->pos);
}

int		ft_nullprecision(t_print **sprt)
{
	if ((*sprt)->sharp == 1 && ft_wii((*sprt)->s[(*sprt)->pos]) == 1)
		return ((*sprt)->pos);
	if (ft_wii((*sprt)->s[(*sprt)->pos]) == 2)
		return ((*sprt)->pos);
	if ((*sprt)->w == 0)
	{
		if ((*sprt)->s[(*sprt)->pos] == 'p')
		{
			(*sprt)->p = -1;
			return ((*sprt)->pos);
		}
		(*sprt)->pos++;
		return (ft_error(sprt));
	}
	else if ((*sprt)->w != 0)
	{
		ft_putchar(ft_wii((*sprt)->zero));
		(*sprt)->size++;
		(*sprt)->pos++;
		return (ft_error(sprt));
	}
	return ((*sprt)->pos);
}

int		ft_wii(char c)
{
	if (c == 'o' || c == 'O')
		return (1);
	else if (c == 'c' || c == 'C')
		return (2);
	else if (c == 'x' || c == 'X')
		return (3);
	else if (c == 1)
		return (48);
	else if (c == 0)
		return (32);
	else
		return (0);
}
