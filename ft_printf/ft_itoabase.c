/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:46:33 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:48:42 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*calc(unsigned int n, int i, char *nbr, unsigned int base)
{
	unsigned int	ret;
	unsigned int	div;

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

char		*ft_itoabase(unsigned int n, unsigned int base)
{
	char	*nbr;
	int		i;

	nbr = ft_strnew(20);
	i = 0;
	return (calc(n, i, nbr, base));
}
