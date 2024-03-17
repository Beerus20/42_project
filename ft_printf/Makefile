.SILENT :
NAME		= libftprintf.a
LIBFT_FILES	= \
	ft_atoi.c				\
	ft_itoa.c				\
	ft_split.c				\
	ft_substr.c				\
	ft_isdigit.c			\
	ft_strlen.c				\
	ft_strjoin.c			\
	ft_strmapi.c			\
	ft_strtrim.c			\
	ft_strchr.c				\
	ft_strncmp.c			\
	ft_strdup.c				\
	ft_striteri.c			\
	ft_putchar_fd.c			\
	ft_putnbr_fd.c			\
	ft_putstr_fd.c			\
	ft_putendl_fd.c			\
	ft_lstnew_bonus.c		\
	ft_lstmap_bonus.c		\
	ft_lstlast_bonus.c		\
	ft_lstiter_bonus.c		\
	ft_lstdelone_bonus.c	\
	ft_lstclear_bonus.c		\
	ft_lstadd_front_bonus.c	\
	ft_lstadd_back_bonus.c	\
	ft_lstsize_bonus.c

LIBFT_OBJS		= $(LIBFT_FILES:%.c=./output/%.o)

FTPRINTF_FILES	= \
	ft_printf.c				\
	ft_check.c				\
	ft_utils.c				\
	ft_utils_num.c			\
	ft_get.c				\
	ft_flags.c				\
	ft_flags_utils.c		\
	ft_treatment.c			\


FTPRINTF_OBJS	= $(FTPRINTF_FILES:%.c=./output/%.o)
BOMBA		= $(subst ./output,./, $(FTPRINTF_OBJS:%.o=%.r))

CFLAGS		= -Wall -Wextra -Werror
RM			= rm -rf
CC			= cc

echo-%-p				:
						echo  $(subst -p, , $(subst echo-, , $@))

./output/%.o		: ./libft/%.c
						@$(CC) $(CFLAGS) -o $@ -c $<

./output/%.o		: ./src/%.c
						@$(CC) $(CFLAGS) -o $@ -c $<

all 				: $(NAME)

$(NAME)				: $(LIBFT_OBJS) $(FTPRINTF_OBJS)
						@ar rc $(NAME) $^

norme				:
						norminette src/* libft/* includes/*

clean 				:
						$(RM) $(LIBFT_OBJS) $(FTPRINTF_OBJS) a.out

fclean				: clean
						$(RM) $(NAME)

cleanall			: fclean vimclean
re					: fclean all
.PHONY				: fclean clean all bonus re
