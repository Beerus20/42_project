.SILENT			:
NAME				= libftprintf.a
FTPRINTF_FILES		= \
	ft_printf.c				\
	ft_check.c				\
	ft_utils.c				\
	ft_utils_num.c			\
	ft_itoa.c				\

FTPRINTF_OBJS		= $(FTPRINTF_FILES:%.c=./output/%.o)

CFLAGS				= -Wall -Wextra -Werror
RM					= rm -rf
CC					= cc

all 				: output $(NAME)

output				:
ifneq ($(shell [ -d output ] && echo true),true)
	@mkdir output
endif

./output/%.o		: %.c
						@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)				: $(FTPRINTF_OBJS)
						@ar rc $(NAME) $^ && mv $(NAME) ../

norme				:
						norminette includes/* *.c

clean 				:
						$(RM) $(FTPRINTF_OBJS) a.out

cleanall			: fclean vimclean
re					: fclean all
.PHONY				: fclean clean all bonus re $(NAME)
