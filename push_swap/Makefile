NAME		=	push_swap
FILES		= \
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
				ft_free.c				\
				main.c

OBJS		=	$(FILES:%.c=output/%.o)
CFLAGS		=	-Wall -Wextra -Werror
CC			=	clang -g


define compile
	$(CC) $(CFLAGS) -c $(1) -o $(2);
endef

all						:	$(NAME)

output					:
							@if [ ! -d output ]; then\
								mkdir output; \
							fi

output/%.o				:	%.c | output
							$(call compile,$<,$@)

$(NAME)					:	$(OBJS)
							make -C ./printf
							$(CC) $(CFLAGS) $(OBJS) -L./printf -lftprintf -o $(NAME)

bonus					:
							make -C ./bonus

test\:%					:	$(NAME)
							valgrind --leak-check=full --track-origins=yes ./push_swap $(subst test:,,$@)

run\:%					:	$(NAME)
							./push_swap $(subst run:,,$@)

gdb\:%					:	$(NAME)
							gdb  -silent --args push_swap $(subst gdb:,,$@)

debug\:%				:	lib
							$(CC) main.c $(FILES) -D DEBUG=1 -L. -lftprintf -o $(NAME)
							./push_swap $(subst debug:,,$@)

clean					:
							make clean -C ./bonus
							make clean -C ./printf
							rm -rf libftprintf.a
							rm -rf $(OBJS) $(BONUS_OBJS) output/main.o output/main_bonus.o

fclean					:	clean
							make fclean -C ./bonus
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
