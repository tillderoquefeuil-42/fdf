/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 17:36:46 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/01/29 13:40:35 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstrf(t_print **sprt)
{
	char	*s;
	char	*str;
	int		i;

	if ((*sprt)->l > 0 || (*sprt)->j > 0)
		return (putmajf(sprt));
	s = va_arg((*sprt)->ap, char*);
	str = ft_strdup(s);
	if ((!str || str[0] == 0) && (*sprt)->w == 0)
	{
		(*sprt)->size--;
		if (!str)
		{
			ft_putstr("(null)");
			(*sprt)->size = (*sprt)->size + 6;
		}
		return (1);
	}
	str = ft_putprecision(sprt, str);
	str = ft_putwidth(sprt, str);
	ft_putstr(str);
	i = ft_strlen(str);
	ft_strdel(&str);
	return (i);
}

int	putmajf(t_print **sprt)
{
	wint_t	*str;
	wint_t	*s;
	int		size;

	s = va_arg((*sprt)->ap, wint_t*);
	str = ft_strwdup(s);
	if (!str || str[0] == 0)
	{
		(*sprt)->size--;
		if (!str)
		{
			ft_putstr("(null)");
			(*sprt)->size = (*sprt)->size + 6;
		}
		return (1);
	}
	str = ft_putspecprecision(sprt, str);
	str = ft_putspecwidth(sprt, str);
	size = ft_putwstr(str);
	ft_memdel((void**)&str);
	return (size);
}

int	putcharf(t_print **sprt)
{
	char	*str;
	int		c;

	if ((*sprt)->l > 0 || (*sprt)->j > 0)
		return (putmajcharf(sprt));
	if ((*sprt)->w < 0)
		str = ft_strnew(-(*sprt)->w);
	else
		str = ft_strnew((*sprt)->w);
	c = (va_arg((*sprt)->ap, int));
	if ((*sprt)->w != 0)
	{
		str[0] = c;
		str = ft_putwidth(sprt, str);
		ft_putstr(str);
		(*sprt)->wtf = 1;
	}
	else
		ft_putchar(c);
	if (str != NULL)
		free(str);
	return ((*sprt)->w + 1);
}

int	putmajcharf(t_print **sprt)
{
	int		size;
	wint_t	c;
	wint_t	*str;

	if ((*sprt)->w < 0)
		str = ft_strwnew(-(*sprt)->w);
	else
		str = ft_strwnew((*sprt)->w);
	c = (va_arg((*sprt)->ap, wint_t));
	if ((*sprt)->w != 0)
	{
		str[0] = c;
		str = ft_putspecwidth(sprt, str);
		size = ft_putwstr(str) + 1;
		(*sprt)->wtf = 1;
	}
	else
		size = ft_putwchar(c);
	if (str != NULL)
		free(str);
	return (size);
}

int	ft_putoptions(t_print **sprt)
{
	if (sprt)
		;
	return (0);
}
