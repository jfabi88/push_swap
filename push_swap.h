/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfabi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:04:36 by jfabi             #+#    #+#             */
/*   Updated: 2021/05/18 17:06:44 by jfabi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_numlist
{
	int					content;
	struct s_numlist	*next;
}				t_numlist;

typedef struct s_vec2
{
	int	begin;
	int end;
	int size;
}				t_vec2;

int		ft_error(int nmb);

/* utils */

t_numlist	*ft_numlstlast(t_numlist *lst);
int			ft_numlist_size(t_numlist *begin_list);
void		ft_numlstadd_back(t_numlist **lst, t_numlist *new);
t_numlist	*ft_numlstnew(int content);
void		ft_numlstadd_front(t_numlist **lst, t_numlist *new);
void		ft_numlist_remove_if(t_numlist **begin_list, int num);
void		ft_print_list(t_numlist *list, char *str);				//delete
int			ft_find_numlast(t_numlist *list);
t_numlist	*ft_copy_list2(t_numlist *list);
void		ft_free_lst(t_numlist *lst);
int			ft_mtx_size(char **mtx);
void		ft_free_mtx(char **mtx);

/* cheker */

void	ft_cheker(t_numlist **lista, t_numlist **listb);
void	ft_change_list(t_numlist **lista, t_numlist **listb, char *str);

/* control */
void	ft_double_control(t_numlist *list);
int		ft_control(int argc, char **argv);

/* push_swap */

void	ft_push_swap_5(t_numlist **lista, t_numlist **listb);
void	ft_push_swap_100(t_numlist **lista, t_numlist **listb);
int		ft_isorder(t_numlist *list);

/* push_swap_utils */

int	ft_find_max(t_numlist *list);
int	ft_find_min(t_numlist *list);
int ft_find_index(t_numlist *list, int data);
int ft_is_ingroup(t_numlist *group, int data);

/* push_swap_utils2 */

void	ft_push_intop(t_numlist **lista, t_numlist **listb, int index);
int		ft_find_best_way(t_numlist *list, int num);
void	ft_change_down(t_numlist **lista, t_numlist **listb);
void	ft_change_up(t_numlist **lista, t_numlist **listb);

/* sottosequenza */

int *ft_find_sequence(t_numlist *list, int num);

/* trasform */
int		*ft_trasform(t_numlist *list);
void    ft_traslate(t_numlist *lista, int *trasl);

#endif