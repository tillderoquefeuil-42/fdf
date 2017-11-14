/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 10:12:18 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:45:36 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putwstr(wint_t *str)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i] != 0)
	{
		size = size + ft_putwchar(str[i]);
		i++;
	}
	return (size);
}
