/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 14:49:24 by tde-roqu          #+#    #+#             */
/*   Updated: 2016/03/22 14:55:56 by tde-roqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"
#include "ft_printf/ft_printf.h"

t_parse	*ft_lstnew(int i, t_env *env)
{
	t_parse	*lst;

	lst = (t_parse*)malloc(sizeof(t_parse));
	if (lst == NULL)
		ft_outfdf(1, env);
	lst->line = (int*)malloc(sizeof(int) * i);
	if (lst->line == NULL)
		ft_outfdf(1, env);
	lst->prox = (int*)malloc(sizeof(int) * i);
	if (lst->line == NULL)
		ft_outfdf(1, env);
	lst->proy = (int*)malloc(sizeof(int) * i);
	if (lst->line == NULL)
		ft_outfdf(1, env);
	lst->next = NULL;
	lst->cn = i;
	return (lst);
}

void	ft_lstadd(t_parse **begin, t_parse *new)
{
	t_parse	*tmp;

	if (*begin != NULL)
	{
		tmp = *begin;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*begin = new;
}

void	ft_lstprint(t_parse *lst, int nc)
{
	t_parse	*tmp;
	t_parse	*tmp2;
	int		i;

	if (lst)
	{
		tmp = lst;
		while (tmp != NULL)
		{
			i = 0;
			tmp2 = tmp;
			tmp = tmp->next;
			while (i < nc)
			{
				ft_printf("%d | ", tmp2->line[i]);
				i++;
			}
			ft_putstr("\n");
		}
	}
}

t_parse	*ft_lstrealloc(t_env *env, t_parse *tmp)
{
	if (tmp->prox)
		free(tmp->prox);
	if (tmp->proy)
		free(tmp->proy);
	tmp->prox = (int*)malloc(sizeof(int) * tmp->cn);
	if (tmp->line == NULL)
		ft_outfdf(1, env);
	tmp->proy = (int*)malloc(sizeof(int) * tmp->cn);
	if (tmp->line == NULL)
		ft_outfdf(1, env);
	return (tmp);
}
