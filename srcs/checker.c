/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 12:37:08 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/08 12:37:12 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_change_list4(t_numlist **lista, t_numlist **listb, char *str)
{
	t_numlist	*temp;
	int			data;
	int			data2;

	if (!ft_strncmp(str, "pa", 3) && ft_numlist_size(*listb) > 0)
	{
		data = (*listb)->content;
		temp = ft_numlstnew(data);
		if (temp == 0)
			ft_error(0);
		temp->next = *lista;
		*lista = temp;
		*listb = (*listb)->next;
	}
	else if (!ft_strncmp(str, "pb", 3) && ft_numlist_size(*lista) > 0)
	{
		data = (*lista)->content;
		temp = ft_numlstnew(data);
		if (temp == 0)
			ft_error(0);
		temp->next = *listb;
		*listb = temp;
		*lista = (*lista)->next;
	}
	printf("%s\n", str);
}

static void	ft_change_list3(t_numlist **lista, t_numlist **listb, char *str)
{
	t_numlist	*temp;
	int			data;
	int			data2;

	data = ft_numlist_size(*listb);
	if ((!ft_strncmp(str, "sb", 3) || (!ft_strncmp(str, "ss", 3))) && data > 1)
	{
		data = (*listb)->content;
		(*listb)->content = (*listb)->next->content;
		(*listb)->next->content = data;
	}
	else if (!ft_strncmp(str, "rrb", 3) || (!ft_strncmp(str, "rrr", 3)))
	{
		temp = *listb;
		data2 = (*listb)->content;
		while ((*listb)->next)
		{
			data = (*listb)->next->content;
			(*listb)->next->content = data2;
			data2 = data;
			*listb = (*listb)->next;
		}
		temp->content = data2;
		*listb = temp;
	}
	ft_change_list4(lista, listb, str);
}

static void	ft_change_list2(t_numlist **lista, t_numlist **listb, char *str)
{
	int			data;
	t_numlist	*temp;

	if (!ft_strncmp(str, "ra", 4) || !ft_strncmp(str, "rr", 4))
	{
		data = (*lista)->content;
		temp = (*lista);
		while ((*lista)->next)
		{
			(*lista)->content = (*lista)->next->content;
			*lista = (*lista)->next;
		}
		(*lista)->content = data;
		*lista = temp;
	}
	if (!ft_strncmp(str, "rb", 4) || !ft_strncmp(str, "rr", 4))
	{
		data = (*listb)->content;
		temp = *listb;
		while ((*listb)->next)
		{
			(*listb)->content = (*listb)->next->content;
			*listb = (*listb)->next;
		}
		(*listb)->content = data;
		*listb = temp;
	}
	ft_change_list3(lista, listb, str);
}

void ft_change_list(t_numlist **lista, t_numlist **listb, char *str)
{
	t_numlist	*temp;
	int			data;
	int			data2;

	data = ft_numlist_size(*lista);
	if ((!ft_strncmp(str, "sa", 3) || (!ft_strncmp(str, "ss", 3))) && data > 1)
	{
		data = (*lista)->content;
		(*lista)->content = (*lista)->next->content;
		(*lista)->next->content = data;
	}
	else if (!ft_strncmp(str, "rra", 3) || (!ft_strncmp(str, "rrr", 3)))
	{
		temp = *lista;
		data2 = (*lista)->content;
		while ((*lista)->next)
		{
			data = (*lista)->next->content;
			(*lista)->next->content = data2;
			data2 = data;
			*lista = (*lista)->next;
		}
		temp->content = data2;
		*lista = temp;
	}
	ft_change_list2(lista, listb, str);
}

void	ft_cheker(t_numlist **lista, t_numlist **listb)
{
	char		*line;

	ft_get_next_line(0, &line);
	ft_change_list(lista, listb, line);
	while (ft_strncmp(line, "", 1) != 0)
	{
		ft_get_next_line(0, &line);
		ft_change_list(lista, listb, line);
	}
	free(line);
}
