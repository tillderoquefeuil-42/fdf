/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xonbrhh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:31:51 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/28 14:14:06 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthnbrf(t_print **sprt)
{
	short	i;
	char	*str;
	int		j;

	i = va_arg((*sprt)->ap, int);
	str = ft_itoa(i);
	str = ft_flag(sprt, (intmax_t)i, str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = minandwidth(str, sprt);
	ft_putstr(str);
	j = ft_strlen(str);
	if (str)
		free(str);
	return (j);
}

int	puthhxoitoa(t_print **sprt)
{
	unsigned char	c;
	char			*str;
	int				j;

	c = va_arg((*sprt)->ap, unsigned int);
	str = ft_itoabase(c, (*sprt)->xo);
	if ((*sprt)->sharp == 1 && c > 0)
		str = ft_sharp(sprt, str);
	if ((*sprt)->s[(*sprt)->pos] == 'X')
		str = ft_mintomaj(str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = sharpandwidth(str);
	ft_putstr(str);
	j = ft_strlen(str);
	if (str)
		free(str);
	return (j);
}

int	puthxoitoa(t_print **sprt)
{
	unsigned short	c;
	char			*str;
	int				j;

	c = va_arg((*sprt)->ap, unsigned int);
	str = ft_itoabase(c, (*sprt)->xo);
	if ((*sprt)->sharp == 1 && c > 0)
		str = ft_sharp(sprt, str);
	if ((*sprt)->s[(*sprt)->pos] == 'X')
		str = ft_mintomaj(str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = sharpandwidth(str);
	ft_putstr(str);
	j = ft_strlen(str);
	if (str)
		free(str);
	return (j);
}
