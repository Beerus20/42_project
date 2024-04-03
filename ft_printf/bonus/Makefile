.SILENT 			:
NAME				= libftprintf.a
MANDATORY_PATH		= ./mandatory
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
	ft_printf_bonus.c				\
	ft_printf_utils_bonus.c		\
	ft_check_bonus.c				\
	ft_utils_bonus.c				\
	ft_utils_num_bonus.c			\
	ft_get_bonus.c				\
	ft_flags_bonus.c				\
	ft_flags_utils_bonus.c		\
	ft_treatment_bonus.c			\
	ft_func_supp_bonus.c			\


FTPRINTF_OBJS		= $(FTPRINTF_FILES:%.c=./output/%.o)

CFLAGS				= -Wall -Wextra -Werror
RM					= rm -rf
CC					= cc

all 				: output $(NAME)

output				:
ifneq ($(shell [ -d output ] && echo true),true)
	@mkdir output
endif

./output/%.o		: ./function/%.c
						@$(CC) $(CFLAGS) -o $@ -c $<

./output/%.o		: ./src/%.c
						@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)				: $(SUPP_FUNCT_OBJS) $(FTPRINTF_OBJS)
						@ar rc $(NAME) $^ && mv $(NAME) ../

norme				:
						norminette includes/* function/* src/*

clean 				:
						$(RM) $(SUPP_FUNCT_OBJS) $(FTPRINTF_OBJS) a.out

cleanall			: fclean vimclean
re					: fclean all
.PHONY				: fclean clean all bonus re
