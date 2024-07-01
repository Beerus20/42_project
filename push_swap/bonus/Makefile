NAME		=	checker
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
				ft_free.c

BONUS	= \
				get_next_line_utils.c	\
				get_next_line.c			\
				main_bonus.c


OBJS		=	$(BONUS:%.c=output/%.o)
FUNC_OBJS	=	$(FILES:%.c=output/%.o)
CFLAGS		=	-Wall -Wextra -Werror
CC			=	clang -g


define compile
		$(CC) $(CFLAGS) -c $(1) -D BONUS=1 -o $(2);
endef

all						:	$(NAME)

output					:
							@if [ ! -d output ]; then\
								mkdir output; \
							fi

output/%.o				:	../%.c | output
							$(call compile,$<,$@)

output/%.o				:	%.c | output
							$(call compile,$<,$@)

output/main.o			:	main.c
							$(call compile,$<,$@)

$(NAME)					:	$(FUNC_OBJS) $(OBJS)
							make -C ../printf
							$(CC) $(CFLAGS) $(FUNC_OBJS) $(OBJS) -L../printf -lftprintf -o $(NAME)
							cp $(NAME) ../$(NAME)

clean					:
							rm -rf $(OBJS) $(FUNC_OBJS)

fclean					:	clean
							rm -rf $(NAME)

push\:%					:	fclean
							git status
							git add .
							git status
							git commit -m "$(subst push:,,$@)"
							git push

re						: fclean all
.PHONY					: all clean fclean re bonus
