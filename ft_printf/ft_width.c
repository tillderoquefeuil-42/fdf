/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:26:28 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 14:10:11 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_optwidth(t_print **sprt, int t, int i, char c)
{
	if (t == 0)
	{
		if ((*sprt)->min == 1)
			(*sprt)->r = 32;
		if ((*sprt)->space == 1 || (*sprt)->plus == 1)
			(*sprt)->w--;
		if ((*sprt)->s[(*sprt)->pos] == 'c' && c != 0)
			(*sprt)->size--;
		if ((*sprt)->s[(*sprt)->pos] == 'c' && c == 0)
			(*sprt)->w--;
		if ((*sprt)->s[(*sprt)->pos] == 'p' && (*sprt)->r == 48)
			(*sprt)->w = (*sprt)->w - 2;
	}
	else if (t == 1)
	{
		if (i < (*sprt)->p - 1)
			(*sprt)->r = 32;
		else if ((*sprt)->min != 1 && (*sprt)->zero == 1)
			(*sprt)->r = 48;
	}
}

char	*ft_putwidth(t_print **sprt, char *str)
{
	int		c;
	char	*s1;
	int		i;
	char	*s2;

	i = 0;
	c = ft_strlen(str);
	ft_optwidth(sprt, 0, i, str[0]);
	if ((*sprt)->w != 0 && c < (*sprt)->w)
	{
		s1 = ft_strnew((*sprt)->w);
		s2 = ft_strnew((*sprt)->w);
		ft_strcpy(s2, str);
		while (c++ < (*sprt)->w)
		{
			ft_optwidth(sprt, 1, i, str[0]);
			s1[i++] = (*sprt)->r;
		}
		if ((*sprt)->min == 0)
			return (freeandret(str, s2, s1));
		return (freeandret(s1, str, s2));
	}
	return (str);
}

int		ft_width(t_print **sprt)
{
	char	*str;
	int		j;
	int		c;

	c = (*sprt)->pos;
	j = (*sprt)->pos;
	while (47 < (*sprt)->s[j] && (*sprt)->s[j] < 58)
		j++;
	str = ft_strsub((*sprt)->s, (*sprt)->pos, j - (*sprt)->pos);
	(*sprt)->pos = j;
	j = ft_atoi(str);
	if ((*sprt)->s[c] == 48 && (*sprt)->min == 0)
	{
		(*sprt)->r = 48;
		(*sprt)->zero = 1;
	}
	(*sprt)->w = j;
	ft_strdel(&str);
	return ((*sprt)->pos);
}

char	*freeandret(char *tofree1, char *tofree2, char *toret)
{
	toret = ft_strcat(toret, tofree1);
	ft_strdel(&tofree1);
	ft_strdel(&tofree2);
	return (toret);
}
