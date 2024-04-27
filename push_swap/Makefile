.SILENT					:
NAME		= push_swap
FILES	= \
	ft_movement.c 		\
	ft_execution.c		\
	ft_free.c			\
	ft_init.c			\
	ft_info.c			\
	ft_check.c			\
	ft_action.c			\
	ft_getters.c		\
	ft_utils.c

# FUNCS		= $(FILES:%.c=./movement/%.c)
FLAGS		= -Wall -Wextra -Werror
CC			= clang -g

all						:	$(NAME)

test\:%					: 	$(NAME)
							valgrind --leak-check=full --track-origins=yes ./push_swap $(subst test:,,$@)

run\:%						: $(NAME)
							./push_swap $(subst run:,,$@)

gdb\:%				: 	$(NAME)
							gdb  -silent --args push_swap $(subst gdb:,,$@)

debug\:%						:
							@$(CC) main.c $(FILES) -D DEBUG=1 -L. -lftprintf -o $(NAME) && ./push_swap $(subst debug:,,$@)

$(NAME)					:	lib $(OBJS)
							$(CC) main.c $(FILES) -L. -lftprintf -o $(NAME)

lib						:
							@cd ./printf && make all

clean					:
							cd ./printf && make clean
							rm -rf libftprintf.a

fclean					: clean
							rm -rf $(NAME)

re						: fclean all
.PHONY					: all clean fclean re $(NAME)
