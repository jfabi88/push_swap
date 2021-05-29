/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:07:04 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/25 12:07:22 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_remove_if(t_numlist **begin_list, int num)
{
	t_numlist	*list;
	t_numlist	*tmp;

	list = *begin_list;
	while (list && list->next)
	{
		if (list->content == num)
		{
			tmp = list->next;
			list->next = list->next->next;
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

int	ft_find_numlast(t_numlist *list)
{
	while (list->next != 0)
		list = list->next;
	return (list->content); 
}

t_numlist	*ft_copy_list2(t_numlist *list)
{
	t_numlist	*temp;
	t_numlist	*cpy;

	cpy = 0;
	while (list != 0)
	{
		temp = ft_numlstnew(list->content);				//malloc
		if (temp == 0)
			ft_error(0);
		ft_numlstadd_back(&cpy, temp);
		list = list->next;
	}
	return (cpy);
}
