/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:05:00 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/25 16:31:30 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_optsharp(t_print **sprt)
{
	if ((*sprt)->sharp == 1)
		return ((*sprt)->pos + 1);
	else
		(*sprt)->sharp = 1;
	return ((*sprt)->pos + 1);
}

int	ft_optmin(t_print **sprt)
{
	if ((*sprt)->min == 1)
		return ((*sprt)->pos + 1);
	else
		(*sprt)->min = 1;
	return ((*sprt)->pos + 1);
}

int	ft_optplus(t_print **sprt)
{
	if ((*sprt)->plus == 1)
		return ((*sprt)->pos + 1);
	else
		(*sprt)->plus = 1;
	return ((*sprt)->pos + 1);
}

int	ft_optspace(t_print **sprt)
{
	if ((*sprt)->space == 1)
		return ((*sprt)->pos + 1);
	else
		(*sprt)->space = 1;
	return ((*sprt)->pos + 1);
}
