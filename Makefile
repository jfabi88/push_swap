NAME	= push_swap

SRCS	=	\
			gnl/get_next_line_utils.c \
			gnl/get_next_line.c \
			srcs/checker.c \
			srcs/control.c \
			srcs/create_list.c \
			srcs/error.c \
			srcs/numlist_utils.c \
			srcs/numlist.c \
			srcs/push_swap_5.c \
			srcs/push_swap_500.c \
			srcs/push_swap.c \
			srcs/trasform.c \
			srcs/utils.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

%.o :	%.c
		gcc -c -g $< -o $@

$(NAME):	$(OBJS)
			make -C libft
			mv libft/libft.a .
			gcc $(CFLAGS) $(OBJS) libft.a -o $(NAME)

all:		$(NAME)

clean:		
			rm -f $(OBJS)
			make -C libft clean

fclean:		clean
			rm -f $(NAME_BONUS)
			rm -f $(NAME) libft.a

re:			fclean all

.PHONY:		all clean fclean re