/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:13:34 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:53:27 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		c;

	i = 0;
	if (!s1)
		return (NULL);
	c = ft_strlen(s1);
	s2 = (char*)malloc(c + 1);
	if (s2 == 0)
		return (0);
	else
	{
		while (i < c)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = 0;
		return (s2);
	}
}
