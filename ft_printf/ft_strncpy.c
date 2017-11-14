/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:50:27 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/25 16:34:43 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (src[i] != '\0')
			dst[i] = src[i];
		else
			while (i < n)
			{
				dst[i] = '\0';
				i++;
			}
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
