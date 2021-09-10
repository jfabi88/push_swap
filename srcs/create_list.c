#include "push_swap.h"

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
		temp = ft_numlstnew(data);
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
