/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 11:41:02 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/19 11:41:04 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isorder(t_numlist *list)
{
	while (list->next != 0)
	{
		if ((int)(list->next->content) < (int)(list->content))
			return (0);
		list = list->next;
	}
	return (1);
}

static void	ft_conclusion(int bool, t_numlist *listb)
{
	if (bool == 1 && listb == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
	size = ft_numlist_size(lista);
	if (size >= 2 && size <= 5)
		ft_push_swap_5(&lista, &listb);
	else
		ft_push_swap_500(&lista, &listb);
	ft_conclusion(ft_isorder(lista), listb);
}