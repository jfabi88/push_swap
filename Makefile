NAME	= push_swap

SRCS	=	\
			checker.c \
			control.c \
			error.c \
			gnl/get_next_line_utils.c \
			gnl/get_next_line.c \
			push_swap_5.c \
			push_swap_100.c \
			push_swap_500.c \
			push_swap_utils.c \
			push_swap_utils2.c \
			push_swap.c \
			reorder_down.c \
			sottosequenza.c \
			trasform.c \
			utils.c \
			utils2.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

%.o :	%.c
		gcc -c -g $< -o $@

$(NAME):	$(OBJS)
			make -C libft
			mv libft/libft.a .
			gcc $(OBJS) libft.a -o $(NAME)

all:		$(NAME)

clean:		
			rm -f $(OBJS)
			make -C libft clean

fclean:		clean clean_bonus
			rm -f $(NAME_BONUS)
			rm -f $(NAME) libft.a

re:			fclean all

.PHONY:		all clean fclean re