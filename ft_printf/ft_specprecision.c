/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specprecision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 13:22:17 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:41:47 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wint_t	*ft_putspecprecision(t_print **sprt, wint_t *str)
{
	int		c;
	wint_t	*s;
	int		i;

	i = 0;
	c = ft_strwlen(str, 1);
	s = ft_strwnew((*sprt)->p);
	if ((*sprt)->p == 0 || (*sprt)->p >= c)
	{
		ft_memdel((void**)&s);
		return (str);
	}
	if ((*sprt)->p < c && (*sprt)->p > 0)
		s = ft_strwncpy(s, str, (*sprt)->p);
	ft_memdel((void**)&str);
	return (s);
}

wint_t	*ft_strwncpy(wint_t *dst, wint_t *src, size_t n)
{
	size_t	i;
	size_t	c;

	i = 0;
	c = speccharsize(src[i]);
	while (c <= n)
	{
		if (src[i])
			dst[i] = src[i];
		else
		{
			while (c <= n)
			{
				dst[i] = 0;
				i++;
				c = c + speccharsize(src[i]);
			}
		}
		i++;
		c = c + speccharsize(src[i]);
	}
	dst[i] = 0;
	return (dst);
}

int		speccharsize(wint_t c)
{
	int	size;

	size = 0;
	if (c <= 127)
		size = size + 1;
	else if (c <= 2047)
		size = size + 2;
	else
		size = size + 3;
	return (size);
}
