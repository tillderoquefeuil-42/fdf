/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 14:15:39 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/28 15:53:44 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	puthhnbrf(t_print **sprt)
{
	char	c;
	char	*str;
	int		j;

	c = va_arg((*sprt)->ap, int);
	str = ft_itoa(c);
	str = ft_flag(sprt, (intmax_t)c, str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = minandwidth(str, sprt);
	ft_putstr(str);
	j = ft_strlen(str);
	ft_strdel(&str);
	return (j);
}

int	putnbrf(t_print **sprt)
{
	int		i;
	char	*str;

	if ((*sprt)->h == 1)
		return (puthnbrf(sprt));
	if ((*sprt)->h == 2)
		return (puthhnbrf(sprt));
	if ((*sprt)->j == 1)
		return (putmaxnbrf(sprt));
	if ((*sprt)->l == 1)
		return (putlnbrf(sprt));
	if ((*sprt)->l == 2 || (*sprt)->z == 1)
		return (putllnbrf(sprt));
	i = va_arg((*sprt)->ap, int);
	str = ft_itoa(i);
	str = ft_flag(sprt, (intmax_t)i, str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = minandwidth(str, sprt);
	ft_putstr(str);
	i = ft_strlen(str);
	ft_strdel(&str);
	return (i);
}

int	putlnbrf(t_print **sprt)
{
	long int	i;
	char		*str;

	if ((*sprt)->j == 1)
		return (putmaxnbrf(sprt));
	if ((*sprt)->l == 2 || (*sprt)->z == 1)
		return (putllnbrf(sprt));
	i = va_arg((*sprt)->ap, long);
	str = ft_litoa(i);
	str = ft_flag(sprt, (intmax_t)i, str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = minandwidth(str, sprt);
	ft_putstr(str);
	i = ft_strlen(str);
	if (str)
		free(str);
	return (i);
}

int	putllnbrf(t_print **sprt)
{
	long long int	i;
	char			*str;

	if ((*sprt)->j == 1)
		return (putumaxnbrf(sprt));
	i = va_arg((*sprt)->ap, long long);
	str = ft_llitoa(i);
	str = ft_flag(sprt, (intmax_t)i, str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = minandwidth(str, sprt);
	ft_putstr(str);
	i = ft_strlen(str);
	ft_strdel(&str);
	return (i);
}

int	putmaxnbrf(t_print **sprt)
{
	intmax_t	i;
	char		*str;

	i = va_arg((*sprt)->ap, intmax_t);
	str = ft_itoamax(i);
	str = ft_flag(sprt, i, str);
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	str = minandwidth(str, sprt);
	ft_putstr(str);
	i = ft_strlen(str);
	ft_strdel(&str);
	return (i);
}
