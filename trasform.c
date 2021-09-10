#include "push_swap.h"

void    ft_change_number(t_numlist *list, int now, int after)
{
    while (list)
    {
        if (list->content == now)
        {
            list->content = after;
            return ;
        }
        list = list->next;
    }
}

void    ft_trasl_list(t_numlist *list, int *trasl)
{
    int size;
    int i;

    size = ft_numlist_size(list);
    i = 0;
    while (i < size)
    {
        ft_change_number(list, trasl[i], i);
        ft_print_list(list, "Lista nel ciclo while");
        i++;
    }
}

int *ft_create_trasl(t_numlist *list)
{
    t_numlist   *cpy;
    int         *trasl;
    int         size;
    int         i;
    int         min;

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

int *ft_trasform(t_numlist *list)
{
    int *trasl;

    trasl = ft_create_trasl(list);
    ft_trasl_list(list, trasl);
    return (trasl);
}

void    ft_traslate(t_numlist *lista, int *trasl)
{
    int i;
    int size;

    i = 0;
    size = ft_numlist_size(lista);
    while (i < size)
    {
        printf("La i è: %d mentra trasl[i] é : %d\n", i, trasl[i]);
        ft_change_number(lista, i, trasl[i]);
        i++;
    }
}