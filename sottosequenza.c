/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sottosequenza.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:53:46 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/28 16:53:48 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free_matrix(int **matrix)
{
	int i;

	i = 0;
	while (matrix[i] != 0)
	{
		free (matrix[i]);
		i++;
	}
	free (matrix);
}

void ft_copy_matrix(int **matrix, int i, int num)
{
	int j;
	int *ret;

	j = 0;
	matrix[i] = malloc(sizeof(int) * (i + 2));
	if (matrix[i] == 0)
	{
		ft_free_matrix(matrix);							//free
		ft_error(0);
	}
	matrix[i + 1] = 0;
	while (j <= (i - 1))
	{
		matrix[i][j] = matrix[i - 1][j];
		j++;
	}
	matrix[i][i] = num;
}

int ft_change_last(int **matrix, int i, int num)
{
	if (matrix[i][i] > num)
	{
		if (i == 0)
		{
			matrix[i][i] = num;
			return (1);
		}
		else
		{
			if (matrix[i][i - 1] < num)
			{
				matrix[i][i] = num;
				return (1);
			}
		}
	}
	return (0);
}

int *ft_copia_riga(int *riga, int i)
{
	int j;
	int *ret;

	ret = malloc(sizeof(int) * (i + 2));
	if (ret == 0)
		return (0);
	j = 0;
	while (j <= i)
	{
		ret[j] = riga[j];
		j++;
	}
	return (ret);
}

int *ft_create(int **matrix, int i, int num)
{
	int *ret;

	ret = 0;
	if (num > matrix[i][i])
	{
		ret = ft_copia_riga(matrix[i], i);
		if (ret == 0)
		{
			ft_free_matrix(matrix);
			ft_error(0);
		}
		ret[i + 1] = num;
	}
	return (ret);
}

int ft_compare(int *first, int *second, int i)
{
	if (first == 0)
		return (0);
	if (second == 0)
		return (1);
	if (first[i] < second[i])
		return (1);
	return (0);
}

void ft_add_content_to_matrix(int **matrix, int num)
{
	int i;
	int flag;
	int *temp;

	i = 0;
	flag = 0;
	while (matrix[i])
	{	
		if (flag == 0)
			flag = ft_change_last(matrix, i, num);
		temp = ft_create(matrix, i, num);
		if (matrix[i + 1] != 0 && ft_compare(temp, matrix[i + 1], i + 1))
		{
			matrix[i + 1] = temp;
			i++;
			flag = 1;
		}
		else
		{
			if (temp != 0)
				free(temp);
		}
		i++;
	}
	if (flag == 0 && i == 0)
		ft_copy_matrix(matrix, i, num);
	else if (flag == 0 && num > matrix[i - 1][i - 2])
		ft_copy_matrix(matrix, i, num);
	matrix[i + 1] = 0;
}

int	*ft_find_last_matrix(int **matrix)
{
	int *ret;
	int i;

	i = 0;
	while (matrix[i + 1])
		i++;
	ret = ft_copia_riga(matrix[i], i);
	if (ret == 0)
	{
		ft_free_matrix(matrix);
		ft_error(0);
	}
	return (ret);
}

int *ft_find_sequence(t_numlist *list, int num)
{
	t_numlist *temp;
	int **matrix;
	int	*ret;
	int j;

	j = 0;
	temp = list;
	matrix = malloc(sizeof(int *) * (num + 1));			//malloc
	if (matrix == 0)
		ft_error(0);
	matrix[0] = 0;
	while (list != 0)
	{
		ft_add_content_to_matrix(matrix, list->content);
		list = list->next;
	}
	while(temp->content != ft_find_last_matrix(matrix)[0])
	{
		ft_add_content_to_matrix(matrix, temp->content);
		temp = temp->next;
	}
	ret = ft_find_last_matrix(matrix);
	ft_free_matrix(matrix);
	int i = 0;
	while (ret[i])
	{
		printf("[%d],", ret[i]);
		i++;
	}
	return (ret);
}
