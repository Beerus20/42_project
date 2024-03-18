.SILENT :
NAME		= libftprintf.a
SUPP_FUNCT_FILES	= \
	ft_atoi.c				\
	ft_itoa.c				\
	ft_isdigit.c			\
	ft_substr.c				\
	ft_strlen.c				\
	ft_strjoin.c			\
	ft_strchr.c				\
	ft_strdup.c				\
	ft_putchar_fd.c			\
	ft_putstr_fd.c			\

SUPP_FUNCT_OBJS		= $(SUPP_FUNCT_FILES:%.c=./output/%.o)

FTPRINTF_FILES		= \
	ft_printf.c				\
	ft_printf_utils.c		\
	ft_check.c				\
	ft_utils.c				\
	ft_utils_num.c			\
	ft_get.c				\
	ft_flags.c				\
	ft_flags_utils.c		\
	ft_treatment.c			\
	ft_func_supp.c			\


FTPRINTF_OBJS		= $(FTPRINTF_FILES:%.c=./output/%.o)

CFLAGS				= -Wall -Wextra -Werror
RM					= rm -rf
CC					= cc


./output/%.o		: ./function/%.c
						@$(CC) $(CFLAGS) -o $@ -c $<

./output/%.o		: ./src/%.c
						@$(CC) $(CFLAGS) -o $@ -c $<

all 				: $(NAME)

$(NAME)				: $(SUPP_FUNCT_OBJS) $(FTPRINTF_OBJS)
						@ar rc $(NAME) $^

norme				:
						norminette includes/* function/* src/*

clean 				:
						$(RM) $(SUPP_FUNCT_OBJS) $(FTPRINTF_OBJS) a.out

fclean				: clean
						$(RM) $(NAME)

cleanall			: fclean vimclean
re					: fclean all
.PHONY				: fclean clean all bonus re
