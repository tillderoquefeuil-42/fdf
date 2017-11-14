/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:04:22 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/02/16 13:28:51 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "ft_printf/ft_printf.h"

static int	reader(char **buf, int const fd)
{
	char	*tmp;
	char	*cpy;
	int		rd;

	tmp = ft_strnew(BUFF_SIZE + 3);
	cpy = ft_strdup(*buf);
	*buf = ft_strnew(ft_strlen(cpy) + BUFF_SIZE + 3);
	if (!tmp || !cpy || !buf)
		return (-1);
	*buf = ft_strcat(*buf, cpy);
	rd = read(fd, tmp, BUFF_SIZE + 3);
	if (rd == -1)
		return (-1);
	*buf = ft_strcat(*buf, tmp);
	if (rd == 0)
	{
		free(tmp);
		free(cpy);
	}
	return (rd);
}

static int	retvalue(char *buf, int *i, int j, char **line)
{
	while (buf[*i] != '\n' && buf[*i] != '\0')
		*i = *i + 1;
	*line = ft_strsub(buf, j, *i - j);
	if (!*line)
		return (-1);
	if (buf[*i] == '\n' || (buf[*i] == '\0' && *i - j > 0))
		return (1);
	else if (buf[*i] == '\0')
	{
		if (buf)
			free(buf);
		return (0);
	}
	return (-1);
}

static int	checkfd(int fd, int i, int *j)
{
	static int	fdj;

	if (i == -1)
		fdj = fd;
	if (fdj != fd)
	{
		fdj = fd;
		i = -1;
	}
	*j = ++i;
	return (i);
}

int			get_next_line(int const fd, char **line)
{
	static int	i = -1;
	static char	*buf;
	int			ret;
	int			j;
	int			rd;

	if (fd < 0 || !line)
		return (-1);
	i = checkfd(fd, i, &j);
	rd = 1;
	if (i == 0)
	{
		if (!(buf = ft_strnew(BUFF_SIZE + 3)))
			return (-1);
		while (rd != 0)
		{
			rd = reader(&buf, fd);
			if (rd == -1)
				return (-1);
		}
	}
	ret = retvalue(buf, &i, j, line);
	if (ret != 1)
		i = -1;
	return (ret);
}
