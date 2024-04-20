NAME		= libftprintf.a
FUNCS		= \
	ft_printf_utils.c
# ft_get_len.c	\
# ft_add_utils.c 	\
# ft_add.c		

BONUS_FUNC	= \
	ft_add_bonus.c					\
	ft_check_flags.c				\
	ft_get_flags.c					\
	ft_utils.c						\
	ft_get_len_bonus.c				\
	ft_char_bonus.c					\
	ft_str_bonus.c					\

OBJS		= $(FUNCS:%.c=./output/%.o)
BONUS_OBJS	= $(BONUS_FUNC:%.c=./output/%.o)
FLAGS		= -Wall -Wextra -Werror
CC			= cc -g

echo					:
							echo $(BONUS_OBJS)

all						: 	$(NAME)

./output/%.o			:	./functions/%.c
							$(CC) $(FLAGS) -c $< -o $@

./output/%.o			:	./bonus/%.c
							$(CC) $(FLAGS) -c $< -o $@

./output/ft_printf.o	:
							$(CC) $(FLAGS) -c ft_printf.c -o $@

$(NAME)					:	$(OBJS) $(BONUS_OBJS) ./output/ft_printf.o
							ar rcs $@ $(OBJS) $(BONUS_OBJS) ./output/ft_printf.o

bonus					:	$(NAME)
							# $(CC) main.c -L. -lftprintf
							# ./a.out

clean					:
							rm -rf $(OBJS) $(BONUS_OBJS) ./output/ft_printf.o

fclean					: clean
							rm -rf $(NAME)

re						: fclean all
.PHONY					: all clean fclean re $(NAME)