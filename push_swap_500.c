#include "push_swap.h"

void    ft_sort(t_numlist **lista, t_numlist **listb, int index)
{
    int size;

    size = ft_numlist_size(*lista);
    while (size > 0)
    {
        if ((((*lista)->content >> index)&1) == 0)
            ft_change_list(lista, listb, "pb");
        else
            ft_change_list(lista, listb, "ra");
        size--;
    }
    while (*listb)
        ft_change_list(lista, listb, "pa");
}

int ft_len_i(t_numlist *lista)
{
    int size;
    int ret;

    ret = 0;
    size = ft_numlist_size(lista);
    while (size > 0)
    {
        size /= 2;
        ret++;
    }
    return (ret);
}

void    ft_sort_500(t_numlist **lista, t_numlist **listb)
{
    int n_i;
    int i;

    n_i = ft_len_i(*lista);
    i = 0;
    while (i < n_i)
    {
        ft_sort(lista, listb, i);
        i++;
    }
}

void    ft_push_swap_500(t_numlist **lista, t_numlist **listb)
{
    int			*trasl;

    trasl = ft_trasform(*lista);
    ft_sort_500(lista, listb);
    ft_traslate(*lista, trasl);
}