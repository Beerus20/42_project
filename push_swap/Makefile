NAME		= push_swap
FILES	= \
	ft_init.c				\
	ft_info.c				\
	ft_transform.c 			\
	ft_movement.c 			\
	ft_execution.c			\
	ft_execution_utils.c	\
	ft_check.c				\
	ft_action.c				\
	ft_action_utils.c		\
	ft_getters.c			\
	ft_add_stack.c			\
	ft_list_utils.c			\
	ft_increase.c			\
	ft_increase_utils.c		\
	ft_increase_functions.c	\
	ft_list_functions.c		\
	ft_show.c				\
	ft_utils.c				\
	ft_free.c				\
	main.c


OBJS		= $(FILES:%.c=%.o)
CFLAGS		= -Wall -Wextra -Werror
CC			= cc

all						:	$(NAME)

%.o						:	%.c
							$(CC) $(CFLAGS) -c $< -o $@

$(NAME)					:	$(OBJS)
							make -C ./printf
							$(CC) $(CFLAGS) $(OBJS) -L./printf -lftprintf -o $(NAME)

test\:%					: 	$(NAME)
							valgrind --leak-check=full --track-origins=yes ./push_swap $(subst test:,,$@)

run\:%					:	$(NAME)
							./push_swap $(subst run:,,$@)

gdb\:%					: 	$(NAME)
							gdb  -silent --args push_swap $(subst gdb:,,$@)

debug\:%				:	lib
							$(CC) main.c $(FILES) -D DEBUG=1 -L. -lftprintf -o $(NAME)
							./push_swap $(subst debug:,,$@)

clean					:
							cd ./printf && make clean
							rm -rf libftprintf.a
							rm -rf $(OBJS)

fclean					: clean
							rm -rf $(NAME)

push\:%					:	fclean
							git status
							git add .
							git status
							git commit -m "$(subst push:,,$@)"
							git push

re						: fclean all
.PHONY					: all clean fclean re
