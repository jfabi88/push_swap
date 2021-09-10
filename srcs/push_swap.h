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

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

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

/* checker */
void		ft_change_list(t_numlist **lista, t_numlist **listb, char *str);
void		ft_cheker(t_numlist **lista, t_numlist **listb);

/* control */
int			ft_control(int argc, char **argv);
void		ft_double_control(t_numlist *list);

/* create_list */
void	ft_copy_list(t_numlist *lista, t_numlist **listb);
void	ft_create_list(t_numlist **lst, t_numlist **blst, int argc, char **argv);

/* error */
int	ft_error(int nmb);

/* numlist_utils */
t_numlist	*ft_copy_list2(t_numlist *list);
void		ft_numlist_remove_if(t_numlist **begin_list, int num);
int			ft_find_max(t_numlist *list);
int			ft_find_min(t_numlist *list);
int 		ft_find_index(t_numlist *list, int data);

/* numlist */
t_numlist	*ft_numlstlast(t_numlist *lst);
int			ft_numlist_size(t_numlist *begin_list);
void		ft_numlstadd_back(t_numlist **lst, t_numlist *new);
void		ft_numlstadd_front(t_numlist **lst, t_numlist *new);
t_numlist	*ft_numlstnew(int content);

/* push_swap_5 */
void ft_push_swap_5(t_numlist **lista, t_numlist **listb);

/* push_swap_500 */
void    ft_push_swap_500(t_numlist **lista, t_numlist **listb);

/* transform */
void    ft_traslate(t_numlist *lista, int *trasl);
int 	*ft_trasform(t_numlist *list);

/* utils */
void	ft_free_lst(t_numlist *lst);
int		ft_mtx_size(char **mtx);
void	ft_free_mtx(char **mtx);

#endif