.SILENT					:
NAME		= push_swap
FILES	= \
	ft_transform.c 		\
	ft_movement.c 		\
	ft_execution.c		\
	ft_free.c			\
	ft_init.c			\
	ft_info.c			\
	ft_check.c			\
	ft_action.c			\
	ft_getters.c		\
	ft_add_stack.c		\
	ft_list_utils.c		\
	ft_increase.c		\
	ft_increase_utils.c	\
	ft_section.c	\
	ft_utils.c

# FUNCS		= $(FILES:%.c=./movement/%.c)
FLAGS		= -Wall -Wextra -Werror
CC			= clang -g

all						:	$(NAME)

test\:%					: 	$(NAME)
							valgrind --leak-check=full --track-origins=yes ./push_swap $(subst test:,,$@)

run\:%					:	$(NAME)
							./push_swap $(subst run:,,$@)

gdb\:%					: 	$(NAME)
							gdb  -silent --args push_swap $(subst gdb:,,$@)

debug\:%				:	lib
							@$(CC) main.c $(FILES) -D DEBUG=1 -L. -lftprintf -o $(NAME) && ./push_swap $(subst debug:,,$@)

$(NAME)					:	lib $(OBJS)
							$(CC) main.c $(FILES) -L. -lftprintf -o $(NAME)

lib						:
							@make -C ./printf

clean					:
							cd ./printf && make clean
							rm -rf libftprintf.a

fclean					: clean
							rm -rf $(NAME)

push\:%					:	fclean
							git status
							git add .
							git status
							git commit -m "$(subst push:,,$@)"
							git push

re						: fclean all
.PHONY					: all clean fclean re $(NAME)
