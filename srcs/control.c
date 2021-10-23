/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:18:34 by jfabi             #+#    #+#             */
/*   Updated: 2021/10/23 11:19:50 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (1);
}

static int	ft_control_int(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_control_str(argv[i]) == -1)
			return (-1);
		i++;
	}
	return (1);
}

static int	ft_control_first(char *str)
{
	char	**mtx;
	int		i;
	int		num;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 0)
		exit (1);
	mtx = ft_split(str, ' ');
	if (mtx == NULL)
		exit(1);
	if (mtx)
		num = ft_control_int(ft_mtx_size(mtx), mtx);
	ft_free_mtx(mtx);
	if (num == -1)
		exit (1);
	return (1);
}

int	ft_control(int argc, char **argv)
{
	if (argc < 2)
		exit (1);
	else if (argc == 2)
		ft_control_first(argv[1]);
	else
	{
		if (ft_control_int(argc - 1, argv + 1) == -1)
			exit (-1);
	}
	return (1);
}
