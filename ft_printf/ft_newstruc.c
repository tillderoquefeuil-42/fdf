/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newstruc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 13:48:08 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/28 13:58:42 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_newstruc(const char *str)
{
	t_print *sprt;

	sprt = (t_print *)malloc(sizeof(t_print));
	if (!sprt)
		exit(0);
	sprt->size = ft_strlen(str);
	sprt->pos = 0;
	sprt->s = ft_strdup(str);
	return (sprt);
}

int		ft_backtozero(t_print **sprt, int c)
{
	c = (*sprt)->pos;
	(*sprt)->w = 0;
	(*sprt)->p = 0;
	(*sprt)->min = 0;
	(*sprt)->plus = 0;
	(*sprt)->space = 0;
	(*sprt)->sharp = 0;
	(*sprt)->r = 32;
	(*sprt)->l = 0;
	(*sprt)->h = 0;
	(*sprt)->j = 0;
	(*sprt)->z = 0;
	(*sprt)->xo = 16;
	(*sprt)->end = 0;
	(*sprt)->wtf = 0;
	(*sprt)->zero = 0;
	(*sprt)->pos++;
	return (c);
}
