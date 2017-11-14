/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:32:51 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/25 16:28:13 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	i;
	int	nbr;
	int	n;

	c = 10;
	i = 0;
	nbr = 0;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\t')
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		n = str[i];
		i++;
	}
	while (47 < str[i] && str[i] < 58)
	{
		nbr = nbr * c + (str[i] - 48);
		i++;
	}
	if (n == 45)
		nbr = -nbr;
	return (nbr);
}
