/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:01:43 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:52:10 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sort(char c)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("sSpdDioOuUxXcC");
	while (str[i] != c && str[i] != 0)
		i++;
	free(str);
	return (i);
}

int	ft_sortopt(char c)
{
	int		i;
	char	*str;

	i = 0;
	if (c == 'l' || c == 'h' || c == 'j' || c == 'z')
		return (7);
	if (47 < c && c < 58)
		return (0);
	str = ft_strdup("#-+ .");
	while (str[i] != c && str[i] != 0)
		i++;
	ft_strdel(&str);
	return (i + 1);
}

int	ft_argfound(t_print **sprt)
{
	int			c;
	static int	(*lstft[15])(t_print**) = {putstrf, putmajf, putptrf, putnbrf,
		putlnbrf, putnbrf, putxoitoa, putxoitoa, putunbrf, putlunbrf,
		putxoitoa, putxoitoa, putcharf, putmajcharf, ft_putoptions};
	static int	(*lstop[8])(t_print**) = {ft_width, ft_optsharp, ft_optmin,
		ft_optplus, ft_optspace, ft_precision, ft_error, ft_mod};

	c = (*lstft[ft_sort((*sprt)->s[(*sprt)->pos])])(sprt);
	if (c == 0)
	{
		(*sprt)->pos = (*lstop[ft_sortopt((*sprt)->s[(*sprt)->pos])])(sprt);
		if ((*sprt)->end == 1)
			return ((*sprt)->pos);
		(*sprt)->pos = ft_argfound(sprt);
	}
	else
		(*sprt)->size = (*sprt)->size + c;
	return ((*sprt)->pos);
}

int	endofprint(t_print **sprt)
{
	int	i;

	i = (*sprt)->size;
	va_end((*sprt)->ap);
	if ((*sprt)->s)
		free((*sprt)->s);
	if (*sprt)
		free(*sprt);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	t_print	*sprt;
	int		c;

	sprt = ft_newstruc(str);
	va_start(sprt->ap, str);
	while (str[sprt->pos] != '\0')
	{
		if (str[sprt->pos] == '%' && str[sprt->pos + 1] != '%')
		{
			c = ft_backtozero(&sprt, c);
			sprt->pos = ft_argfound(&sprt);
			sprt->size = sprt->size + (c - sprt->pos) - 1;
			if (sprt->wtf == 1)
				break ;
		}
		else if (str[sprt->pos] == '%' && str[++sprt->pos] == '%')
		{
			sprt->size--;
			ft_putchar(str[sprt->pos]);
		}
		else
			ft_putchar(str[sprt->pos]);
		sprt->pos++;
	}
	return (endofprint(&sprt));
}
