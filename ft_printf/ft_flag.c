/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:51:13 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 14:02:44 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_flag(t_print **sprt, long long int nbr, char *str)
{
	char	*nb;

	nb = ft_strnew(ft_strlen(str) + 1);
	if (((*sprt)->plus == 1 || (*sprt)->space == 1) && (*sprt)->w != 0)
	{
		if ((*sprt)->p > 0)
			(*sprt)->p++;
		(*sprt)->w = (*sprt)->w + 1;
	}
	if (nbr >= 0 && (*sprt)->plus == 1)
	{
		ft_strcpy(nb, "+");
		nb = ft_strcat(nb, str);
		ft_strdel(&str);
		return (nb);
	}
	else if (nbr >= 0 && (*sprt)->space == 1)
	{
		ft_strcpy(nb, " ");
		nb = ft_strcat(nb, str);
		ft_strdel(&str);
		return (nb);
	}
	ft_strdel(&nb);
	return (str);
}

char	*minandwidth(char *nbr, t_print **sprt)
{
	int		i;
	char	c;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] == '0' && (nbr[i + 1] == '-' || nbr[i + 1] == '+'
			|| (nbr[i + 1] == ' ' && (*sprt)->min == 0)))
		{
			c = nbr[i + 1];
			nbr[i + 1] = '0';
			while (nbr[i] == '0' && i > 0)
				i--;
			if (nbr[i] == ' ')
				i++;
			nbr[i] = c;
			return (nbr);
		}
		i++;
	}
	return (nbr);
}

char	*sharpandwidth(char *nbr)
{
	int		i;
	char	c;

	i = 0;
	while (nbr[i])
	{
		if (nbr[i] == '0' && (nbr[i + 1] == 'x' || nbr[i + 1] == 'X'))
		{
			c = nbr[i + 1];
			nbr[i + 1] = '0';
			while (nbr[i] == '0' && i > 0)
				i--;
			if (nbr[i] == ' ')
				i++;
			nbr[i + 1] = c;
			return (nbr);
		}
		i++;
	}
	return (nbr);
}

char	*ft_sharp(t_print **sprt, char *str)
{
	char	*nbr;

	nbr = ft_strnew(ft_strlen(str) + 3);
	if (!nbr)
		return (NULL);
	if ((*sprt)->s[(*sprt)->pos] == 'x')
	{
		ft_strcpy(nbr, "0x");
		nbr = ft_strcat(nbr, str);
	}
	if ((*sprt)->s[(*sprt)->pos] == 'X')
	{
		ft_strcpy(nbr, "0X");
		nbr = ft_strcat(nbr, str);
	}
	if ((*sprt)->p > 0 && ft_wii((*sprt)->s[(*sprt)->pos]) == 3)
		(*sprt)->p = (*sprt)->p + 2;
	if ((*sprt)->s[(*sprt)->pos] == 'o' || (*sprt)->s[(*sprt)->pos] == 'O')
	{
		ft_strcpy(nbr, "0");
		nbr = ft_strcat(nbr, str);
	}
	ft_strdel(&str);
	return (nbr);
}
