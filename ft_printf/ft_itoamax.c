/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoamax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 18:03:31 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:50:05 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*longmin(char *nbr)
{
	ft_strcpy(nbr, "-9223372036854775808");
	return (nbr);
}

static char	*calc(intmax_t n, int i, char *nbr)
{
	intmax_t	ret;
	intmax_t	div;

	ret = 0;
	div = 1;
	while (n / div > 9)
		div = div * 10;
	while (div >= 1)
	{
		ret = n / div;
		n = n % div;
		nbr[i] = ret + 48;
		div = div / 10;
		i++;
	}
	nbr[i] = 0;
	return (nbr);
}

char		*ft_itoamax(intmax_t n)
{
	char	*nbr;
	int		i;

	nbr = ft_strnew(25);
	if (n == LLONG_MIN)
		return (longmin(nbr));
	i = 0;
	if (n < 0)
	{
		n = -n;
		nbr[i] = '-';
		i++;
	}
	return (calc(n, i, nbr));
}
