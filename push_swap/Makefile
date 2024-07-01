NAME		= push_swap
FILES	= \
	ft_init.c				\
	ft_info.c				\
	ft_params.c				\
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
	ft_free.c

BONUS		= \
				get_next_line_utils.c	\
				get_next_line.c
				

OBJS		= $(FILES:%.c=output/%.o)
BONUS_FILES	= $(BONUS:%.c=bonus/%.c)
BONUS_OBJS	= $(BONUS_FILES:bonus/%.c=output/%.o)
CFLAGS		= -Wall -Wextra -Werror
CC			= clang -g

all						:	$(NAME)

output					:
							@if [ ! -d output ]; then\
								mkdir output; \
							fi

output/%.o				:	%.c | output
							$(CC) $(CFLAGS) -c $< -o $@

output/%.o				:	./bonus/%.c | output
							$(CC) $(CFLAGS) -c $< -o $@

$(NAME)					:	$(OBJS) output/main.o
							make -C ./printf
							$(CC) $(CFLAGS) $(OBJS) output/main.o -L./printf -lftprintf -o $(NAME)

output/main.o			:	main.c
							$(CC) $(CFLAGS) -c $< -o $@

output/main_bonus.o		:	./bonus/main_bonus.c
							$(CC) $(CFLAGS) -c $< -o $@

bonus					:	checker

checker					:	$(OBJS) $(BONUS_OBJS) output/main_bonus.o
							$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) output/main_bonus.o -L./printf -lftprintf -o checker

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
							make clean -C ./printf
							rm -rf libftprintf.a
							rm -rf $(OBJS) $(BONUS_OBJS) output/main.o output/main_bonus.o

fclean					: clean
							make fclean -C ./printf
							rm -rf $(NAME) $(BONUS_OBJS) checker

push\:%					:	fclean
							git status
							git add .
							git status
							git commit -m "$(subst push:,,$@)"
							git push

re						: fclean all
.PHONY					: all clean fclean re bonus
