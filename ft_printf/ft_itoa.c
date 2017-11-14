/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:46:33 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/28 16:13:28 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*minint(char *nbr)
{
	ft_strcpy(nbr, "-2147483648");
	return (nbr);
}

static char	*calc(int n, int i, char *nbr)
{
	int	ret;
	int	div;

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

char		*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	nbr = ft_strnew(14);
	if (n == -2147483648)
		return (minint(nbr));
	i = 0;
	if (n < 0)
	{
		n = -n;
		nbr[i] = '-';
		i++;
	}
	return (calc(n, i, nbr));
}
