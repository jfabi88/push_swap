/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:07:04 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/25 12:07:22 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_numlist_remove_if(t_numlist **begin_list, int num)
{
	t_numlist	*list;
	t_numlist	*tmp;

	list = *begin_list;
	while (list && list->next)
	{
		if (list->next->content == num)
		{
			tmp = list->next;
			list->next = tmp->next;
			free(tmp);
		}
		list = list->next;
	}
	list = *begin_list;
	if (list && list->content == num)
	{
		*begin_list = list->next;
		free(list);
	}
}

void	ft_push_intop(t_numlist **lista, t_numlist **listb, int index)
{
	int	size;

	size = ft_numlist_size(*lista);
	if (size - index > size / 2)
	{
		while (index > 0)
		{
			ft_change_list(lista, listb, "ra");
			index--;
		}
	}
	else
	{
		while (size - index > 0)
		{
			ft_change_list(lista, listb, "rra");
			index++;
		}
	}
}

int	ft_find_best_way(t_numlist *list, int num)
{
	int i;
	int	size;

	i = 0;
	size = ft_numlist_size(list);
	list  = list->next;
	while (list != 0 && num < list->content)
	{
		i++;
		list = list->next;
	}
	if (i <= (size - 1 - i) + 1)
		return (0);
	return (1);
}

void	ft_change_up(t_numlist **lista, t_numlist **listb)
{
	int index;

	while ((*listb)->content > ft_find_numlast(*listb))
	{
		ft_change_list(lista, listb, "rrb");
		ft_change_list(lista, listb, "sb");
	}
	while ((*listb)->content != ft_find_max(*listb))
		ft_change_list(lista, listb, "rb");
}

void ft_change_down(t_numlist **lista, t_numlist **listb)
{
	int	index;

	while ((*listb)->content < (*listb)->next->content)
	{
		ft_change_list(lista, listb, "sb");
		if((*listb)->next->content < (*listb)->next->next->content)
		{
			if ((*listb)->next->next->content != ft_find_max(*listb))
				ft_change_list(lista, listb, "rb");
		}
		}
	index = ft_find_index(*listb, ft_find_max(*listb));
	ft_push_intop(listb, lista, index);
}
