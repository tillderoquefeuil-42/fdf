/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabasellu.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:46:33 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:48:53 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*longmax(char *nbr, int base)
{
	if (base == 10)
		ft_strcpy(nbr, "18446744073709551615");
	else if (base == 8)
		ft_strcpy(nbr, "1777777777777777777777");
	else if (base == 16)
		ft_strcpy(nbr, "ffffffffffffffff");
	else
		return (0);
	return (nbr);
}

static char	*calc(long long unsigned int n, int i, char *nbr,\
	long long unsigned int base)
{
	long long unsigned int	ret;
	long long unsigned int	div;

	ret = 0;
	div = 1;
	while (n / div >= base)
		div = div * base;
	while (div >= 1)
	{
		ret = n / div;
		n = n % div;
		if (ret < 10)
			nbr[i] = ret + 48;
		else
			nbr[i] = 'a' + ret - 10;
		div = div / base;
		i++;
	}
	nbr[i] = 0;
	return (nbr);
}

char		*ft_itoabasellu(long long unsigned int n,\
	long long unsigned int base)
{
	char	*nbr;
	int		i;

	nbr = ft_strnew(20);
	if (n == ULLONG_MAX)
		return (longmax(nbr, base));
	i = 0;
	return (calc(n, i, nbr, base));
}
