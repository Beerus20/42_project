NAME		= libftprintf.a
FUNCS		= \
	ft_get_len.c		\
	ft_add_utils.c 		\
	ft_add.c			\
	ft_printf.c

HEADERS		= \
	ft_add.h		\
	ft_get_len.h	\
	ft_printf.h

INCLUDES		= $(HEADERS:%.h=./includes/%.h)
OBJS			= $(FUNCS:%.c=./output/%.o)
FLAGS			= -Wall -Wextra -Werror -fPIC
CC				= cc

all						:	$(NAME)

output					:
							@if [ ! -d output ]; then\
								mkdir output; \
							fi

./output/%.o			:	./functions/%.c | output
							$(CC) $(FLAGS) -c $< -o $@

$(NAME)					:	$(OBJS)
							ar -rcs $@ $^

clean					:
							rm -rf $(OBJS) $(NAME)

fclean					: 	clean
							rm -rf $(NAME)

re						: fclean all
.PHONY					: all clean fclean re
