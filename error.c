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

void	ft_error1(int nmb)
{
	if (nmb == 0)
		printf("Errore nella gestione della malloc\n");
	if (nmb == 1)
		printf("I parametri passati non sono corretti\n");
	if (nmb == 2)
		printf("Dei numeri sono ripetuti due volte\n");
}

void	ft_error(int nmb)
{
	if (nmb >= 0 && nmb < 5)
		ft_error1(nmb);
	/* free */
	exit(1);
}
