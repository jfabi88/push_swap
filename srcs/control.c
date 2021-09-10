#include "push_swap.h"

static int	ft_is_valid_nmb(char *str, int *j)
{
	int	flag;

	if (ft_isdigit(str[*j]))
		return (1);
	else if (str[*j] == '-' || str[*j] == '+')
	{
		flag = 1;
		if (str[*j] == '-')
			flag = 2;
		(*j)++;
		if (!ft_isdigit(str[*j]))
			return (-1);
		return (flag);
	}
	return (-1);
}

static int	ft_control_str(char *str)
{
	int	i;
	int	num;
	int	val;
	int	sgn;

	i = 0;
	num = 0;
	while (str[i])
	{
		sgn = ft_is_valid_nmb(str, &i);
		if (sgn == -1)
			return (ft_error(1));
		val = str[i] - 48;
		if (num >= 0 && (2147483647 - val) / 10 < num)
			return (ft_error(1));
		else if (num < 0 && (-2147483648 + val) / 10 > num)
			return (ft_error(1));
		if (sgn == 2 || num < 0)
			num = (num * 10) - val;
		else
			num = (num * 10) + val;
		i++;
	}
}

static int	ft_control_int(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_control_str(argv[i]);
		i++;
	}
	return (1);
}

int ft_control(int argc, char **argv)
{
    char    **mtx;

    if (argc < 2)
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
