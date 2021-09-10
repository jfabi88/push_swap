/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:42:14 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/20 17:42:16 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numlist	*ft_copy_list2(t_numlist *list)
{
	t_numlist	*temp;
	t_numlist	*cpy;

	cpy = 0;
	while (list != 0)
	{
		temp = ft_numlstnew(list->content);
		if (temp == 0)
			ft_error(0);
		ft_numlstadd_back(&cpy, temp);
		list = list->next;
	}
	return (cpy);
}

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

int	ft_find_max(t_numlist *list)
{
	int	ret;

	ret = list->content;
	while (list->next)
	{
		if (list->content > ret)
			ret = list->content;
		list = list->next;
	}
	if (list->content > ret)
		ret = list->content;
	return (ret);
}

int	ft_find_min(t_numlist *list)
{
	int	ret;

	ret = list->content;
	while (list->next)
	{
		if (list->content < ret)
			ret = list->content;
		list = list->next;
	}
	if (list->content < ret)
		ret = list->content;
	return (ret);
}

int	ft_find_index(t_numlist *list, int data)
{
	int	i;

	i = 0;
	while (list->next)
	{
		if (list->content == data)
			return (i);
		list = list->next;
		i++;
	}
	return (i);
}
