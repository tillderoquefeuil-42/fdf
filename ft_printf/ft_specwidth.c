/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 15:26:28 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:52:58 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wint_t	*ft_putspecwidth(t_print **sprt, wint_t *str)
{
	int		c;
	wint_t	*s1;
	int		i;
	wint_t	*s2;

	i = 0;
	c = ft_strwlen(str, 1);
	if ((*sprt)->space == 1 || (*sprt)->plus == 1 || (*sprt)->s[(*sprt)->pos]
		== 'C' || (*sprt)->s[(*sprt)->pos] == 'c')
		(*sprt)->w--;
	if ((*sprt)->w != 0 && c < (*sprt)->w)
	{
		s1 = ft_strwnew((*sprt)->w);
		while (c++ < (*sprt)->w)
			s1[i++] = (*sprt)->r;
		if ((*sprt)->min == 0)
			s2 = ft_strwcat(s1, str, (*sprt)->w);
		if ((*sprt)->min == 1)
			s2 = ft_strwcat(str, s1, (*sprt)->w);
		ft_memdel((void**)&s1);
		ft_memdel((void**)&str);
		return (s2);
	}
	return (str);
}

wint_t	*ft_strwcat(wint_t *s1, wint_t *s2, int size)
{
	int		i;
	int		j;
	wint_t	*str;

	str = ft_strwnew(size);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}

wint_t	*ft_strwdup(wint_t *s1)
{
	wint_t	*s2;
	int		i;
	int		c;

	i = 0;
	if (!s1)
		return (NULL);
	c = ft_strwlen(s1, 0);
	s2 = (wint_t*)malloc(sizeof(wint_t) * (c + 1));
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

wint_t	*ft_strwnew(int size)
{
	wint_t	*str;
	int		i;

	i = 0;
	str = (wint_t*)malloc(sizeof(wint_t) * size);
	if (str == NULL)
		return (NULL);
	else
	{
		while (i < size)
		{
			str[i] = 0;
			i++;
		}
		return (str);
	}
}

int		ft_strwlen(wint_t *s, int t)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	if (t == 1)
	{
		while (s[i])
		{
			if (s[i] <= 127)
				size = size + 1;
			else if (s[i] <= 2047)
				size = size + 2;
			else
				size = size + 3;
			i++;
		}
		return (size);
	}
	while (s[i])
		i++;
	return (i);
}
