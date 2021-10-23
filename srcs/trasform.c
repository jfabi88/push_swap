/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trasform.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:16:56 by jfabi             #+#    #+#             */
/*   Updated: 2021/10/23 11:16:58 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_change_number(t_numlist *list, int *trasl)
{
	int	i;

	i = 0;
	while (trasl[i] != list->content)
		i++;
	list->content = i;
}

static void	ft_trasl_list(t_numlist *list, int *trasl)
{
	int	size;
	int	i;

	size = ft_numlist_size(list);
	i = 0;
	while (list)
	{
		ft_change_number(list, trasl);
		list = list->next;
	}
}

static int	*ft_create_trasl(t_numlist *list)
{
	t_numlist	*cpy;
	int			*trasl;
	int			size;
	int			i;
	int			min;

	cpy = ft_copy_list2(list);
	if (cpy == NULL)
		ft_error(0);
	size = ft_numlist_size(list);
	trasl = (int *)malloc(sizeof(int) * size);
	if (trasl == NULL)
	{
		ft_free_lst(cpy);
		ft_error(0);
	}
	i = 0;
	while (i < size)
	{
		min = ft_find_min(cpy);
		trasl[i] = min;
		ft_numlist_remove_if(&cpy, min);
		i++;
	}
	return (trasl);
}

int	*ft_trasform(t_numlist *list)
{
	int	*trasl;

	trasl = ft_create_trasl(list);
	ft_trasl_list(list, trasl);
	return (trasl);
}

void	ft_traslate(t_numlist *lista, int *trasl)
{
	int	i;
	int	size;

	i = 0;
	size = ft_numlist_size(lista);
	while (i < size)
	{
		lista->content = trasl[lista->content];
		lista = lista->next;
		i++;
	}
}
