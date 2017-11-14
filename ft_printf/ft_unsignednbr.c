/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignednbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:17:10 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/28 14:22:44 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthhunbrf(t_print **sprt)
{
	unsigned char	c;
	char			*str;
	int				j;

	c = va_arg((*sprt)->ap, unsigned int);
	str = ft_itoa(c);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	ft_putstr(str);
	j = ft_strlen(str);
	if (str)
		free(str);
	return (j);
}

int	putunbrf(t_print **sprt)
{
	unsigned int	i;
	char			*str;

	if ((*sprt)->h == 2)
		return (puthhunbrf(sprt));
	if ((*sprt)->j == 1)
		return (putumaxnbrf(sprt));
	if ((*sprt)->l == 1)
		return (putlunbrf(sprt));
	if ((*sprt)->l == 2 || (*sprt)->z == 1)
		return (putllunbrf(sprt));
	i = va_arg((*sprt)->ap, unsigned int);
	str = ft_itoabase(i, 10);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	ft_putstr(str);
	i = ft_strlen(str);
	if (str)
		free(str);
	return (i);
}

int	putlunbrf(t_print **sprt)
{
	long unsigned int	i;
	char				*str;

	if ((*sprt)->j == 1)
		return (putumaxnbrf(sprt));
	if ((*sprt)->l == 2 || (*sprt)->z == 1)
		return (putllunbrf(sprt));
	i = va_arg((*sprt)->ap, long unsigned int);
	str = ft_itoabaselu(i, 10);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	ft_putstr(str);
	i = ft_strlen(str);
	if (str)
		free(str);
	return (i);
}

int	putllunbrf(t_print **sprt)
{
	long long unsigned int	i;
	char					*str;

	i = va_arg((*sprt)->ap, long long unsigned int);
	str = ft_itoabasellu(i, 10);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	ft_putstr(str);
	i = ft_strlen(str);
	if (str)
		free(str);
	return (i);
}

int	putumaxnbrf(t_print **sprt)
{
	uintmax_t	i;
	char		*str;

	if ((*sprt)->l == 2)
		return (putllunbrf(sprt));
	i = va_arg((*sprt)->ap, uintmax_t);
	str = ft_itoabaseumax(i, 10);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	ft_putstr(str);
	i = ft_strlen(str);
	if (str)
		free(str);
	return (i);
}
