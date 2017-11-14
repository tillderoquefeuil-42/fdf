/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:46:50 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/28 14:37:04 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_error(t_print **sprt)
{
	(*sprt)->end = ft_nonvalid(sprt);
	if ((*sprt)->s[(*sprt)->pos] == '%')
	{
		ft_putchar((*sprt)->s[(*sprt)->pos]);
		(*sprt)->size++;
	}
	return ((*sprt)->pos - 1);
}

int	ft_nonvalid(t_print **sprt)
{
	char	c;
	int		t;

	t = 0;
	c = ft_wii((*sprt)->zero);
	if ((*sprt)->min == 1)
	{
		ft_putchar((*sprt)->s[(*sprt)->pos]);
		(*sprt)->pos++;
	}
	if (ft_sort((*sprt)->s[(*sprt)->pos - 1]) == 14 && (*sprt)->w != 0
		&& (*sprt)->s[(*sprt)->pos - 2] == '.')
	{
		(*sprt)->w = (*sprt)->w - 1;
		t = 1;
		(*sprt)->size++;
	}
	else if (ft_sort((*sprt)->s[(*sprt)->pos - 1]) == 14
		&& (*sprt)->s[(*sprt)->pos - 2] == '0'
		&& (*sprt)->s[(*sprt)->pos - 3] == '.')
	{
		t = 1;
		(*sprt)->size++;
	}
	return (ft_ifw(sprt, c, t));
}

int	ft_ifw(t_print **sprt, char c, int t)
{
	if ((*sprt)->w != 0)
		(*sprt)->w = (*sprt)->w - 1;
	if ((*sprt)->w < 0)
	{
		(*sprt)->w = -(*sprt)->w;
		c = '0';
	}
	while ((*sprt)->w > 0)
	{
		ft_putchar(c);
		(*sprt)->w--;
		(*sprt)->size++;
	}
	if ((*sprt)->min == 1)
		(*sprt)->size++;
	if (t == 1)
		ft_putchar((*sprt)->s[(*sprt)->pos - 1]);
	return (1);
}
