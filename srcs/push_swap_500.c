#include "push_swap.h"

static int	ft_sort(t_numlist **lista, t_numlist **listb, int index)
{
	int	size;

	size = ft_numlist_size(*lista);
	while (size > 0)
	{
		if ((((*lista)->content >> index) & 1) == 0)
		{
			if (ft_change_push(lista, listb, "pb") == -1)
				return (-1);
		}
		else
			ft_change_list(lista, listb, "ra");
		size--;
	}
	while (*listb)
	{
		if (ft_change_push(lista, listb, "pa") == -1)
			return (-1);
	}
	return (1);
}

static int	ft_len_i(t_numlist *lista)
{
	int	size;
	int	ret;

	ret = 0;
	size = ft_numlist_size(lista);
	while (size > 0)
	{
		size /= 2;
		ret++;
	}
	return (ret);
}

static int	ft_sort_500(t_numlist **lista, t_numlist **listb)
{
	int	n_i;
	int	i;

	n_i = ft_len_i(*lista);
	i = 0;
	while (i < n_i)
	{
		if (ft_sort(lista, listb, i) == -1)
			return (-1);
		i++;
	}
	return (1);
}

void	ft_push_swap_500(t_numlist **lista, t_numlist **listb)
{
	int	*trasl;

	trasl = ft_trasform(*lista);
	if (ft_sort_500(lista, listb) == -1)
	{
		free(trasl);
		ft_free_exit(*lista, *listb);
	}
	ft_traslate(*lista, trasl);
	free(trasl);
}
