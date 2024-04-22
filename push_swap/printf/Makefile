.SILENT					:
NAME		= libftprintf.a
FUNCS		= \
	ft_get_len.c		\
	ft_add_utils.c 		\
	ft_add.c

HEADERS		= \
	ft_add.h		\
	ft_get_len.h	\
	ft_printf.h

INCLUDES		= $(HEADERS:%.h=./includes/%.h)
SRC_OBJ			= ./output/ft_printf.o
OBJS			= $(FUNCS:%.c=./output/%.o)
FLAGS			= -Wall -Wextra -Werror
CC				= clang -g

all						:	output $(NAME)

output					:
							@if [ ! -d output ]; then\
								mkdir output; \
							fi

./output/%.o			:	./functions/%.c
							$(CC) $(FLAGS) -c $< -o $@

$(SRC_OBJ)				:
							$(CC) $(FLAGS) -c ft_printf.c -o $@

$(NAME)					:	$(OBJS) $(SRC_OBJ)
							ar rcs $@ $(OBJS) $(SRC_OBJ) $(INCLUDES) && mv $(NAME) ..

clean					:
							@rm -rf $(OBJS) $(SRC_OBJ) $(NAME)

fclean					: 	clean
							@rm -rf $(NAME)

re						: fclean all
.PHONY					: all clean fclean re $(NAME)
