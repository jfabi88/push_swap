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

int	ft_find_max(t_numlist *list)
{
	int ret;

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
	int ret;

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

int ft_find_index(t_numlist *list, int data)
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

int ft_is_ingroup(t_numlist *group, int data)
{
	while (group->next)
	{
		if (group->content == data)
			return (1);
		group = group->next;
	}
	if (group->content == data)
		return (1);
	return (0);
}
