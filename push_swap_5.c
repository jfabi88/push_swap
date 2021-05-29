/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:32:32 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/20 17:32:35 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_third_step(t_numlist **lista, t_numlist **listb)
{
	int index_min;
	int	index_max;

	index_min = ft_find_index(*lista, ft_find_min(*lista));
	index_max = ft_find_index(*lista, ft_find_max(*lista));
	if (index_min == 0 && index_max == 1)
	{
		ft_change_list(lista, listb, "sa");
		ft_change_list(lista, listb, "ra");
	}
	else if (index_min == 1 && index_max == 0)
		ft_change_list(lista, listb, "rra");
	else if (index_min == 2 && index_max == 0)
	{
		ft_change_list(lista, listb, "ra");
		ft_change_list(lista, listb, "sa");
	}
	else if (index_min == 2 && index_max == 1)
		ft_change_list(lista, listb, "ra");
}

void ft_second_step(t_numlist **lista, t_numlist **listb, int max)
{
	int index;

	index = ft_find_index(*lista, max);
	if (index == 1)
		ft_change_list(lista, listb, "sa");
	else if (index == 2)
	{
		ft_change_list(lista, listb, "ra");
		ft_change_list(lista, listb, "ra");
	}
	else if (index == 3)
		ft_change_list(lista, listb, "rra");
	ft_change_list(lista, listb, "pb");
}

void ft_first_step(t_numlist **lista, t_numlist **listb, int min)
{
	int	index;

	index = ft_find_index(*lista, min);
	if (index == 1)
		ft_change_list(lista, listb, "sa");
	else if (index == 2)
	{
		ft_change_list(lista, listb, "ra");
		ft_change_list(lista, listb, "ra");
	}
	else if (index == 3)
	{
		ft_change_list(lista, listb, "ra");
		ft_change_list(lista, listb, "ra");
		ft_change_list(lista, listb, "ra");
	}
	else if (index == 4)
		ft_change_list(lista, listb, "rra");
	ft_change_list(lista, listb, "pb");
}

void ft_push_swap_5(t_numlist **lista, t_numlist **listb)
{
	int min;
	int max;

	min = ft_find_min(*lista);
	max = ft_find_max(*lista);
	ft_first_step(lista, listb, min);
	ft_second_step(lista, listb, max);
	ft_third_step(lista, listb);
	ft_change_list(lista, listb, "pa");
	ft_change_list(lista, listb, "ra");
	ft_change_list(lista, listb, "pa");
}
