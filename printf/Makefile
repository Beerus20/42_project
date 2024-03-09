NAME		= libftprintf.a
LSRCS		= \
	ft_strlen.c   ft_substr.c ft_putnbr_fd.c ft_strdup.c ft_putstr_fd.c ft_putendl_fd.c	ft_putchar_fd.c	ft_itoa.c	ft_split.c
LOBJS		= $(LSRCS:%.c=%.o)

SRCS		= \
	function.c		utils.c		ft_printf.c		ft_number.c
OBJS		= $(SRCS:%.c=%.o)

CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
CC			= cc

%.o					: %.c
						@$(CC) $(CFLAGS) -o $@ -c $<

all 				: $(NAME)

$(NAME)				: $(LOBJS) $(OBJS)
						@ar rc $(NAME) $^

norme				:
						norminette

clean 				:
						$(RM) $(OBJS) $(LOBJS) a.out

fclean				: clean
						$(RM) $(NAME)

cleanall			: fclean vimclean
re					: fclean all
.PHONY				: fclean clean all bonus re
