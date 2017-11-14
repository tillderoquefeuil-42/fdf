/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_othernbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:39:16 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 14:02:31 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptrf(t_print **sprt)
{
	long unsigned int	i;
	char				*s;
	char				*str;
	int					size;

	i = va_arg((*sprt)->ap, long unsigned int);
	s = ft_itoabaselu(i, 16);
	size = sizeinit(s, sprt);
	str = ft_strnew(size);
	ft_strcpy(str, "0x");
	if ((*sprt)->p >= 0)
	{
		s = ft_putprecision(sprt, s);
		if ((*sprt)->r == 48)
		{
			s = ft_putwidth(sprt, s);
			ft_strcat(str, s);
		}
		else if ((*sprt)->r == 32)
		{
			ft_strcat(str, s);
			str = ft_putwidth(sprt, str);
		}
	}
	return (endofptrf(str, size, s));
}

int	sizeinit(char *s, t_print **sprt)
{
	int	size;

	size = ft_strlen(s) + 3;
	if ((*sprt)->w > size)
		size = (*sprt)->w + 3;
	return (size);
}

int	endofptrf(char *str, int size, char *s)
{
	ft_putstr(str);
	size = ft_strlen(str);
	ft_strdel(&s);
	ft_strdel(&str);
	return (size);
}
