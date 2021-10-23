/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:17:49 by jfabi             #+#    #+#             */
/*   Updated: 2021/10/23 11:17:51 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_copy_list(t_numlist *lista, t_numlist **listb)
{
	t_numlist	*temp;
	int			data;

	while (lista->next)
	{
		data = lista->content;
		temp = ft_numlstnew(data);
		if (temp == 0)
			return (ft_error(0));
		ft_numlstadd_back(listb, temp);
		lista = lista->next;
	}
	data = lista->content;
	temp = ft_numlstnew(data);
	if (temp == 0)
		return (ft_error(0));
	ft_numlstadd_back(listb, temp);
	return (1);
}

static int	ft_c_lst(t_numlist **lst, t_numlist **blst, int argc, char **argv)
{
	t_numlist	*temp;
	int			i;
	int			data;

	i = 0;
	while (i < argc)
	{	
		data = ft_atoi(argv[i]);
		temp = ft_numlstnew(data);
		if (temp == 0)
			return (ft_error(0));
		ft_numlstadd_back(lst, temp);
		i++;
	}
	return (1);
}

void	ft_create_list(t_numlist **lst, t_numlist **blst, int argc, char **argv)
{
	char	**mtx;
	int		num;

	if (argc == 2)
	{
		mtx = ft_split(argv[1], ' ');
		if (mtx)
			num = ft_c_lst(lst, blst, ft_mtx_size(mtx), mtx);
		ft_free_mtx(mtx);
		if (num == -1)
		{
			ft_free_lst(*lst);
			ft_free_lst(*blst);
			exit (-1);
		}
	}
	else
		ft_c_lst(lst, blst, argc - 1, argv + 1);
}
