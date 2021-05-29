/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_100.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 17:57:49 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/21 17:57:52 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_reorder(t_numlist **lista, t_numlist **listb)
{
	int	index;
	int	flag;

	flag = ft_find_best_way(*listb, (*listb)->content);
	if (ft_numlist_size(*listb) == 2)
	{
		while ((*listb)->content < (*listb)->next->content)
			ft_change_list(lista, listb, "sb");
	}
	else if ((*listb)->content == ft_find_min(*listb))
		ft_change_list(lista, listb, "rb");
	else if (ft_numlist_size(*listb) > 2 && flag == 0)
		ft_change_down(lista, listb);
	else if (ft_numlist_size(*listb) > 2 && flag == 1)
		ft_change_up(lista, listb);
}

t_numlist	*create_group(t_numlist *list, int min, int max)
{
	t_numlist	*ret;
	t_numlist	*temp;
	t_numlist	*copy;
	int			difference;
	int			i;

	i = 0;
	copy = ft_copy_list2(list);
	ret = 0;
	difference = max - min;
	while (i < difference)
	{
		min = ft_find_min(copy);
		ft_numlist_remove_if(&copy, min);
		temp = ft_numlstnew(min);				//una malloc da disallocare
		if (temp == 0)
			ft_error(0);
		ft_numlstadd_back(&ret, temp);
		i++;
	}
	free(copy);
	return (ret);
}

int	ft_find_hold(t_numlist *lista, t_numlist *group)
{
	int i;
	int	ret;
	int ret2;
	int	size;

	i = 0;
	size = ft_numlist_size(lista);
	ret = -1;
	ret2 = -1;
	while (i < size)
	{
		if (i > size / 2 && ft_is_ingroup(group, lista->content))
			ret2 = i;
		else if (ret == -1 && ft_is_ingroup(group, lista->content))
			ret = i;
		i++;
		lista = lista->next;
	}
	if (size - ret2 < ret || ret < 0)
		return (ret2);
	return (ret);
}

void ft_step1(t_numlist **lista, t_numlist **listb, int min, int max)
{
	t_numlist	*group;
	int			hold;
	int			i;
	int			size;

	i = 0;
	size = ft_numlist_size(*lista);
	group = create_group(*lista, min, max);                  //fatta una malloc
	while (i < max - min)
	{
		hold = ft_find_hold(*lista, group);
		ft_push_intop(lista, listb, hold);
		ft_change_list(lista, listb, "pb");
		if (ft_numlist_size(*listb) > 1 && (*listb)->content > (*listb)->next->content)
			ft_change_list(lista, listb, "sb");
		i++;
	}
	free(group);											//malloc liberata
}

void ft_push_swap_100(t_numlist **lista, t_numlist **listb)
{
	int	size;
	int	num;
	int max;
	int mod;

	size = ft_numlist_size(*lista);
	mod = size % 5; 
	num = 0;
	while (num < 5)
	{
		max = (num * ((size + mod)/ 5)) + ((size + mod) / 5);
		ft_step1(lista, listb, num * ((size + mod) / 5), max);
		num++;
	}
	while (*listb != 0)
	{
		num = ft_find_index(*listb, ft_find_max(*listb));
		ft_push_intop(listb, lista, num);
		ft_change_list(lista, listb, "pa");
	}
}