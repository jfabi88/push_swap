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

int	ft_isorder(t_numlist *list)
{
	//ft_print_list(list);			//delete
	while (list->next != 0)
	{
		if ((int)(list->next->content) < (int)(list->content))
			return (0);
		list = list->next;
	}
	return (1);
}

void	ft_conclusion(int bool, t_numlist *listb)
{
	if (bool == 1 && listb == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return ;
}

void	ft_copy_list(t_numlist *lista, t_numlist **listb)
{
	t_numlist	*temp;
	int			data;

	while (lista->next)
	{
		data = lista->content;
		temp = ft_numlstnew(data);
		if (temp == 0)
			ft_error(0);
		ft_numlstadd_back(listb, temp);
		lista = lista->next;
	}
	data = lista->content;
	temp = ft_numlstnew(data);
	if (temp == 0)
		ft_error(0);
	ft_numlstadd_back(listb, temp);
}

static void	ft_c_lst(t_numlist **lst, t_numlist **blst, int argc, char **argv)
{
	t_numlist	*temp;
	int			i;
	int			data;

	i = 0;
	while (i < argc)
	{	
		data = ft_atoi(argv[i]);
		temp = ft_numlstnew(data);					//malloc
		if (temp == 0)
			ft_error(0);
		ft_numlstadd_back(lst, temp);
		i++;
	}
}

void	ft_create_list(t_numlist **lst, t_numlist **blst, int argc, char **argv)
{
	char	**mtx;

	if (argc == 2)
	{
		mtx = ft_split(argv[1], ' ');
		if (mtx)
			ft_c_lst(lst, blst, ft_mtx_size(mtx), mtx);
		ft_free_mtx(mtx);
	}
	else
		ft_c_lst(lst, blst, argc - 1, argv + 1);
}

int	main(int argc, char **argv)
{
	t_numlist	*lista;
	t_numlist	*listb;
	int			size;
	int			*trasl;

	lista = NULL;
	listb = NULL;
	ft_control(argc, argv);
	ft_create_list(&lista, &listb, argc, argv);
	ft_double_control(lista);
	size = ft_numlist_size(lista);
	//ft_print_list(lista, "La lista A è");
	//ret = ft_find_sequence(lista, size);
	if (size >= 2 && size <= 5)
		ft_push_swap_5(&lista, &listb);
	ft_print_list(lista, "lista");	
	trasl = ft_trasform(lista);
	//if (size > 5 && size <= 100)
	//	ft_push_swap_100(lista, listb);
	//ft_cheker(&lista, &listb);
	ft_print_list(lista, "lista");						//delete
	ft_print_list(listb, "listb");						//delete
	ft_traslate(lista, trasl);
	ft_print_list(lista, "lista");
	ft_conclusion(ft_isorder(lista), listb);
}