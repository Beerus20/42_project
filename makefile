# variables
NAME		= libft
LIBNAME		= libft.a
SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)
CFLAGS		= -Wall -Wextra -Werror
VIMFILES	= .*.swp

#commandes
RM			= rm -rf
CC			= cc

*.o 		:	*.c
				${CC} $(CFLAGS) -c $^
$(NAME)		:
				$(CC) -o $(OBJS)
norme		:
				norminette
lib			:
				ar rc $(LIBNAME) $(OBJS)
all 		: norme $(NAME)

clean 		: 
				$(RM) $(OBJS)
vimclean	:
				$(RM) $(VIMFILE)
fclean		: clean
				$(RM) $(NAME)
cleanall	: fclean vimclean
re			: fclean all
.PHONY		: fclean clean all
