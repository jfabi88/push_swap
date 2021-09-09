#include "push_swap.h"

static int	ft_control_int(int argc, char **argv)
{
	int	i;
	int	j;
	int	num;
	int val;

	i = 0;
	while (i < argc)
	{
		j = 0;
		num = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (ft_error(1));
			val = ft_atoi(&argv[i][j]);
			if ((long int)(2147483647 - val) < num)
				return (ft_error(1));
			if ((long int)(-2147483648 - val) > num)
				return (ft_error(1));
			num += val;
			j++;
		}
		i++;
	}
	return (1);
}

int ft_control(int argc, char **argv)
{
    char    **mtx;

    if (argc == 1)
        exit (1);
	if (argc == 2)
    {
        mtx = ft_split(argv[1], ' ');
        if (mtx)
		    return (ft_control_int(ft_mtx_size(mtx), mtx));
        ft_free_mtx(mtx);
    }
	else
		return (ft_control_int(argc - 1, argv + 1));
}

void	ft_double_control(t_numlist *list)
{
	t_numlist	*cpy;
	t_numlist	*start;

	start = list;
	while (list->next != 0)
	{
		cpy  = list->next;
		while (cpy->next != 0)
		{
			if (cpy->content == list->content)
			{
				ft_free_lst(start);
				ft_error(2);
			}
			cpy = cpy->next;
		}
		if (cpy->content == list->content)
		{
			ft_free_lst(start);
			ft_error(2);
		}
		list = list->next;
	}
	list = start;
}
