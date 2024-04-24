NAME		= push_swap
FILES	= \
	ft_movement.c 		\
	ft_utils.c			\
	ft_analyses.c		\
	ft_actions.c		\
	ft_info.c

# FUNCS		= $(FILES:%.c=./movement/%.c)
FLAGS		= -Wall -Wextra -Werror
CC			= clang -g

all						:	$(NAME)



$(NAME)					:	lib $(OBJS)
							$(CC) main.c $(FILES) -L. -lftprintf -o $(NAME)

lib						:
							cd ./printf && make all

clean					:
							cd ./printf && make clean
							rm -rf libftprintf.a
							
fclean					: clean
							rm -rf $(NAME)

re						: fclean all
.PHONY					: all clean fclean re $(NAME)
