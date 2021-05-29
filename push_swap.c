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

void	ft_create_list(t_numlist **lst, t_numlist **blst, int argc, char **argv)
{
	t_numlist	*temp;
	int			i;
	int			data;

	i = 1;
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

void	ft_control(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while(i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				ft_error(1);
			j++;
		}
		i++;
	}
}

void	ft_double_control(t_numlist *list)
{
	t_numlist	*cpy;

	while (list->next != 0)
	{
		cpy  = list->next;
		while (cpy->next != 0)
		{
			if (cpy->content == list->content)
				ft_error(2);
			cpy = cpy->next;
		}
		if (cpy->content == list->content)
			ft_error(2);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	t_numlist	**lista;
	t_numlist	**listb;
	int			size;
	int			flag;
	int			*ret;

	lista = malloc(sizeof(t_numlist **));
	listb = malloc(sizeof(t_numlist **));
	*lista = 0;
	*listb = 0;
	ft_control(argc, argv);
	ft_create_list(lista, listb, argc, argv);
	ft_double_control(*lista);
	size = ft_numlist_size(*lista);
	ret = ft_find_sequence(*lista, size);
	//if (size >= 4 && size <= 5)
	//	ft_push_swap_5(lista, listb);
	//if (size > 5 && size <= 100)
	//	ft_push_swap_100(lista, listb);
	//ft_cheker(&lista, &listb);
	//ft_print_list(lista, "lista");						//delete
	//ft_print_list(listb, "listb");						//delete
	//ft_conclusion(ft_isorder(*lista), *listb);
}