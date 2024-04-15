NAME		= libftprintf.a
FUNCS		= \
	ft_add.c			\
	ft_add_utils.c		\
	ft_get_len.c		\
	ft_printf_utils.c
OBJS		= $(FUNCS:%.c=./output/%.o)
FLAGS		= -Wall -Wextra -Werror
CC			= cc

echo					:
							echo $(OBJS)

debug					:
							$(CC) main.c -L. -lftprintf && lldb ./a.out

test					:
							$(CC) main.c -L. -lftprintf && ./a.out

all						: $(NAME)

./output/%.o			: ./functions/%.c
							$(CC) $(FLAGS) -c $< -o $@

./output/ft_printf.o	:
							$(CC) $(FLAGS) -c ft_printf.c -o $@

$(NAME)					:  $(OBJS) ./output/ft_printf.o
							ar rcs $@ $(OBJS) ./output/ft_printf.o

clean					:
							rm -rf $(OBJS)

fclean					: clean
							rm -rf $(NAME)

re						: fclean all
.PHONY					: all clean fclean re $(NAME)