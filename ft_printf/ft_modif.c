/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:49:51 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/25 16:30:57 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mod(t_print **sprt)
{
	if ((*sprt)->s[(*sprt)->pos] == 'l' && (*sprt)->l == 0)
	{
		if ((*sprt)->s[(*sprt)->pos + 1] == 'l')
			(*sprt)->l++;
		(*sprt)->l++;
		return ((*sprt)->pos + (*sprt)->l);
	}
	else if ((*sprt)->s[(*sprt)->pos] == 'h' && (*sprt)->h == 0)
	{
		if ((*sprt)->s[(*sprt)->pos + 1] == 'h')
			(*sprt)->h++;
		(*sprt)->h++;
		return ((*sprt)->pos + (*sprt)->h);
	}
	else if ((*sprt)->s[(*sprt)->pos] == 'j' && (*sprt)->h == 0)
		(*sprt)->j++;
	else if ((*sprt)->s[(*sprt)->pos] == 'z' && (*sprt)->z == 0)
		(*sprt)->z++;
	return ((*sprt)->pos + 1);
}
