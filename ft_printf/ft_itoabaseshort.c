/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabaseshort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:46:33 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:49:15 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*calc(char n, int i, char *nbr, int base)
{
	char	ret;
	char	div;

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

char		*ft_itoabaseshort(char n, int base)
{
	char	*nbr;
	int		i;

	nbr = ft_strnew(12);
	i = 0;
	return (calc(n, i, nbr, base));
}
