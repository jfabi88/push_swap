/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:41:02 by jfabi             #+#    #+#             */
/*   Updated: 2021/10/23 11:18:20 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_double_control(t_numlist *list)
{
	t_numlist	*cpy;
	t_numlist	*start;

	start = list;
	while (list->next != 0)
	{
		cpy = list->next;
		while (cpy->next != 0)
		{
			if (cpy->content == list->content)
			{
				ft_free_lst(start);
				exit(ft_error(2));
			}
			cpy = cpy->next;
		}
		if (cpy->content == list->content)
		{
			ft_free_lst(start);
			exit (ft_error(2));
		}
		list = list->next;
	}
	list = start;
}

static int	ft_isorder(t_numlist *list)
{
	while (list && list->next != 0)
	{
		if ((int)(list->next->content) < (int)(list->content))
			return (0);
		list = list->next;
	}
	return (1);
}

static void	ft_conclusion(int bool, t_numlist *listb)
{
	if (bool != 1 || listb != 0)
		write(1, "Error\n", 6);
	return ;
}

int	main(int argc, char **argv)
{
	t_numlist	*lista;
	t_numlist	*listb;
	int			size;
	int			*sottoquenza;

	lista = NULL;
	listb = NULL;
	ft_control(argc, argv);
	ft_create_list(&lista, &listb, argc, argv);
	ft_double_control(lista);
	if (ft_isorder(lista) == 1)
	{
		ft_free_exit(lista, listb);
		return (1);
	}
	size = ft_numlist_size(lista);
	if (size >= 2 && size <= 5)
		ft_push_swap_5(&lista, &listb);
	else if (size > 5)
		ft_push_swap_500(&lista, &listb);
	ft_conclusion(ft_isorder(lista), listb);
	ft_free_lst(lista);
	ft_free_lst(listb);
}
