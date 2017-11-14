/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xonbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:23:33 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/28 12:47:32 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_truedirection(t_print **sprt)
{
	if ((*sprt)->s[(*sprt)->pos] == 'o' || (*sprt)->s[(*sprt)->pos] == 'O')
		(*sprt)->xo = 8;
	if ((*sprt)->h == 2 && (*sprt)->s[(*sprt)->pos] != 'O')
		return (puthhxoitoa(sprt));
	if ((*sprt)->h == 1 && (*sprt)->s[(*sprt)->pos] != 'O')
		return (puthxoitoa(sprt));
	if ((*sprt)->j == 1)
		return (putxoitoaumax(sprt));
	if ((*sprt)->l == 1 || ((*sprt)->s[(*sprt)->pos] == 'O' &&
		(*sprt)->h != 2))
		return (putxoitoalu(sprt));
	if ((*sprt)->l == 2 || (*sprt)->z == 1)
		return (putxoitoallu(sprt));
	else
		return (-1);
}

int	putxoitoa(t_print **sprt)
{
	unsigned int	i;
	char			*str;
	int				c;

	c = ft_truedirection(sprt);
	if (c != -1)
		return (c);
	i = va_arg((*sprt)->ap, unsigned int);
	str = ft_itoabase(i, (*sprt)->xo);
	if ((*sprt)->sharp == 1 && i > 0)
		str = ft_sharp(sprt, str);
	if ((*sprt)->s[(*sprt)->pos] == 'X')
		str = ft_mintomaj(str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = sharpandwidth(str);
	ft_putstr(str);
	i = ft_strlen(str);
	if (str)
		free(str);
	return (i);
}

int	putxoitoalu(t_print **sprt)
{
	long unsigned int	i;
	char				*str;

	if ((*sprt)->h == 2)
		return (puthhxoitoa(sprt));
	if ((*sprt)->j == 1)
		return (putxoitoaumax(sprt));
	if ((*sprt)->l == 2 || (*sprt)->z == 1)
		return (putxoitoallu(sprt));
	i = va_arg((*sprt)->ap, long unsigned int);
	str = ft_itoabaselu(i, (*sprt)->xo);
	if ((*sprt)->sharp == 1 && i > 0)
		str = ft_sharp(sprt, str);
	if ((*sprt)->s[(*sprt)->pos] == 'X')
		str = ft_mintomaj(str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = sharpandwidth(str);
	ft_putstr(str);
	i = ft_strlen(str);
	if (str)
		free(str);
	return (i);
}

int	putxoitoallu(t_print **sprt)
{
	long long unsigned int	i;
	char					*str;

	i = va_arg((*sprt)->ap, long long unsigned int);
	str = ft_itoabasellu(i, (*sprt)->xo);
	if ((*sprt)->sharp == 1 && i > 0)
		str = ft_sharp(sprt, str);
	if ((*sprt)->s[(*sprt)->pos] == 'X')
		str = ft_mintomaj(str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = sharpandwidth(str);
	ft_putstr(str);
	i = ft_strlen(str);
	if (str)
		free(str);
	return (i);
}

int	putxoitoaumax(t_print **sprt)
{
	uintmax_t	i;
	char		*str;

	i = va_arg((*sprt)->ap, uintmax_t);
	str = ft_itoabaseumax(i, (*sprt)->xo);
	if ((*sprt)->sharp == 1 && i > 0)
		str = ft_sharp(sprt, str);
	if ((*sprt)->s[(*sprt)->pos] == 'X')
		str = ft_mintomaj(str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = sharpandwidth(str);
	ft_putstr(str);
	i = ft_strlen(str);
	if (str)
		free(str);
	return (i);
}
