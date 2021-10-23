/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:16:17 by jfabi             #+#    #+#             */
/*   Updated: 2021/10/23 11:16:46 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_exit(t_numlist *lista, t_numlist *listb)
{
	ft_free_lst(lista);
	ft_free_lst(listb);
	exit(-1);
}

void	ft_free_lst(t_numlist *lst)
{
	t_numlist	*pointer;

	while (lst)
	{
		pointer = lst->next;
		free(lst);
		lst = pointer;
	}
}

int	ft_mtx_size(char **mtx)
{
	int	i;

	i = 0;
	if (mtx == NULL)
		return (-1);
	while (mtx[i])
		i++;
	return (i);
}

void	ft_free_mtx(char **mtx)
{
	int	i;

	i = 0;
	while (mtx && mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}
