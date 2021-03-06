/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:00:13 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/18 17:00:16 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_error1(int nmb)
{
	if (nmb == 0)
		ft_putendl_fd("Error", 2);
	if (nmb == 1)
		ft_putendl_fd("Error", 2);
	if (nmb == 2)
		ft_putendl_fd("Error", 2);
}

int	ft_error(int nmb)
{
	if (nmb >= 0 && nmb < 5)
		ft_error1(nmb);
	return (-1);
}
