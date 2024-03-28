NAME			= libftprintf.a
FTPRINTF_FILES		= \
	ft_printf.c				\
	ft_check.c				\
	ft_utils_num.c			\
	ft_itoa.c				\

FTPRINTF_OBJS		= $(FTPRINTF_FILES:%.c=./output/%.o)

CFLAGS				= -Wall -Wextra -Werror
RM					= rm -rf
CC					= cc

all 				: output $(NAME)

output				:
						mkdir $@

./output/%.o		: %.c
						@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)				: $(FTPRINTF_OBJS)
						@ar rc $(NAME) $^ && mv $(NAME) ..

norme				:
						norminette includes/* function/* src/*

clean 				:
						$(RM) $(FTPRINTF_OBJS) a.out

fclean				: clean
						cd .. && $(RM) $(NAME)

cleanall			: fclean vimclean
re					: fclean all
.PHONY				: fclean clean all bonus re
