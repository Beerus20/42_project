NAME		= libft
LIBNAME		= libft.a
SRCS		= \
	ft_atoi.c        ft_isalpha.c  ft_memchr.c    ft_putchar_fd.c  ft_strchr.c    ft_strlcpy.c  ft_strrchr.c	\
	ft_bzero.c       ft_isascii.c  ft_memcmp.c    ft_putendl_fd.c  ft_strdup.c    ft_strlen.c   ft_strtrim.c	\
	ft_calloc.c      ft_isdigit.c  ft_memcpy.c    ft_putnbr_fd.c   ft_striteri.c  ft_strmapi.c  ft_substr.c		\
	ft_isprint.c     ft_memmove.c  ft_putstr_fd.c ft_strjoin.c     ft_strncmp.c   ft_tolower.c  ft_isalnum.c	\
	ft_itoa.c        ft_memset.c   ft_split.c     ft_strlcat.c     ft_strnstr.c   ft_toupper.c	
OBJS		= $(SRCS:.c=.o)
VIMFILES	= ./.*.swp
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
CC			= cc

all 		: norme $(NAME) lib

run			: norme
				$(CC) $(CFLAGS) -c main.c -L. -lft

$(NAME)		: $(OBJS)

outputs/%.o	: src/%.c
				${CC} $(CFLAGS) -o $@ -c $<

norme		:
				norminette

lib			:
				ar rc $(LIBNAME) $(OBJS)

clean 		: 
				$(RM) $(OBJS)

vimclean	:
				$(RM) $(VIMFILE)

fclean		: clean
				$(RM) $(NAME)

cleanall	: fclean vimclean
re			: fclean all
.PHONY		: fclean clean all
