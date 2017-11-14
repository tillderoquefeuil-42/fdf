/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 18:14:38 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/28 15:08:56 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		*ft_convmask(char *nbr, int i, int j, int *tab)
{
	char	*ret;

	ret = ft_strnew(8);
	while (i < 8)
		ret[j++] = nbr[i++];
	tab[0] = ft_btoi(ret);
	if (nbr[i])
	{
		j = 0;
		while (i < 16)
			ret[j++] = nbr[i++];
		tab[1] = ft_btoi(ret);
		if (nbr[i])
		{
			j = 0;
			while (i < 24)
				ret[j++] = nbr[i++];
			tab[2] = ft_btoi(ret);
		}
	}
	if (ret)
		free(ret);
	return (tab);
}

char	*ft_putmask(char *mask, char *nbr, int end)
{
	int	i;

	end = end - 1;
	i = ft_strlen(mask) - 1;
	while (i >= 0 && end >= 0)
	{
		if (mask[i] == 'x')
			mask[i] = nbr[end--];
		i--;
	}
	while (i >= 0)
	{
		if (mask[i] == 'x')
			mask[i] = '0';
		i--;
	}
	return (mask);
}

char	*ft_mask(char *nbr, int *c, int nb)
{
	char	*mask;
	int		end;

	end = ft_strlen(nbr);
	if (nb <= 127)
	{
		mask = ft_strdup("0xxxxxxx");
		*c = 1;
	}
	else if (nb <= 2047)
	{
		mask = ft_strdup("110xxxxx10xxxxxx");
		*c = 2;
	}
	else
	{
		*c = 3;
		mask = ft_strdup("1110xxxx10xxxxxx10xxxxxx");
	}
	mask = ft_putmask(mask, nbr, end);
	if (nbr)
		free(nbr);
	return (mask);
}

int		ft_putwchar(wint_t nb)
{
	char	*nbr;
	int		*tab;
	int		i;
	int		c;

	c = 0;
	tab = (int*)malloc(sizeof(int) * 3);
	if (tab)
	{
		i = -1;
		nbr = ft_itoabase(nb, 2);
		nbr = ft_mask(nbr, &c, nb);
		tab = ft_convmask(nbr, 0, 0, tab);
		while (++i < c)
			write(1, &tab[i], 1);
		free(tab);
		if (nbr)
			free(nbr);
	}
	return (c);
}
