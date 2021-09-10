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

static void ft_third_step(t_numlist **lista, t_numlist **listb)
{
	int index_min;
	int	index_max;

	index_min = ft_find_index(*lista, ft_find_min(*lista));
	index_max = ft_find_index(*lista, ft_find_max(*lista));
	if (ft_numlist_size(*lista) != 2 && index_min == 0 && index_max == 1)
	{
		ft_change_list(lista, listb, "sa");
		ft_change_list(lista, listb, "ra");
	}
	else if (index_min == 1 && index_max == 0)
		ft_change_list(lista, listb, "ra");
	else if (index_min == 1 && index_max == 2)
		ft_change_list(lista, listb, "sa");
	else if (index_min == 2 && index_max == 0)
	{
		ft_change_list(lista, listb, "ra");
		ft_change_list(lista, listb, "sa");
	}
	else if (index_min == 2 && index_max == 1)
		ft_change_list(lista, listb, "rra");
}

static void ft_second_step(t_numlist **lista, t_numlist **listb, int max)
{
	int index;

	index = ft_find_index(*lista, max);
	if (index == 1)
		ft_change_list(lista, listb, "sa");
	else if (index == 2 && ft_numlist_size(*lista) == 4)
	{
		ft_change_list(lista, listb, "ra");
		ft_change_list(lista, listb, "ra");
	}
	else if (index == 2)
		ft_change_list(lista, listb, "rra");
	else if (index == 3)
		ft_change_list(lista, listb, "rra");
	ft_change_list(lista, listb, "pb");
}

static void ft_first_step(t_numlist **lista, t_numlist **listb, int min)
{
	int	index;
	int	i;

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
		i = 0;
		while (i < ft_numlist_size(*lista) - index)
		{
			ft_change_list(lista, listb, "rra");
			i++;
		}
	}
	else if (index == 4)
		ft_change_list(lista, listb, "rra");
	ft_change_list(lista, listb, "pb");
}

void ft_push_swap_5(t_numlist **lista, t_numlist **listb)
{
	int min;
	int max;
	int	start_size;

	start_size = ft_numlist_size(*lista);
	if ( start_size >= 4)
	{
		min = ft_find_min(*lista);
		max = ft_find_max(*lista);
		ft_first_step(lista, listb, min);
		ft_second_step(lista, listb, max);
		ft_third_step(lista, listb);
		ft_change_list(lista, listb, "pa");
		ft_change_list(lista, listb, "ra");
		ft_change_list(lista, listb, "pa");
	}
	else
		ft_third_step(lista, listb);
}
