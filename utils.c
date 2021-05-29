/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:51:31 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/19 10:51:33 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_numlist	*ft_numlstlast(t_numlist *lst)
{
	t_numlist	*cpy;

	if (lst == 0)
		return (0);
	cpy = lst;
	while (cpy->next != 0)
		cpy = cpy->next;
	return (cpy);
}

int	ft_numlist_size(t_numlist *begin_list)
{
	t_numlist	*list;
	int			ret;

	ret = 0;
	list = begin_list;
	while (list)
	{
		ret++;
		list = list->next;
	}
	return (ret);
}

void	ft_numlstadd_back(t_numlist **lst, t_numlist *new)
{
	t_numlist	*cpy;

	if (lst != 0)
	{
		if (*lst == 0)
			*lst = new;
		else
		{
			cpy = ft_numlstlast(*lst);
			cpy->next = new;
		}
	}
}

void	ft_numlstadd_front(t_numlist **lst, t_numlist *new)
{
	if (lst == 0)
	{
		*lst = 0;
		return ;
	}
	if (new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}

t_numlist	*ft_numlstnew(int content)
{
	t_numlist	*diz;

	diz = malloc(sizeof(t_numlist *));
	if (diz == 0)
		ft_error(0);
	diz->content = content;
	diz->next = 0;
	return (diz);
}

void	ft_print_list(t_numlist *list, char *str)					//delete
{
	if (str != 0)
		printf("%s: ", str);
	while (list->next != 0)
	{
		printf("%d", list->content);
		printf(", ");
		list = list->next;
	}
	printf("%d\n", list->content);
}
