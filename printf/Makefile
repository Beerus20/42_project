NAME		= libftprintf.a
FUNCS		= \
	ft_get_len.c		\
	ft_add_utils.c 		\
	ft_add.c		

BONUS_FUNC	= \
	ft_add_bonus.c					\
	ft_get_flags_bonus.c			\
	ft_utils_bonus.c				\
	ft_get_len_bonus.c				

BONUS_TYPES_FUNC = \
	ft_char_bonus.c					\
	ft_str_bonus.c					\
	ft_number_bonus.c				\
	ft_unumber_bonus.c				\
	ft_hex_bonus.c					\
	ft_pointer_bonus.c				

SRC_OBJ			= ./output/ft_printf.o
OBJS				= $(FUNCS:%.c=./output/%.o)
BONUS_OBJS			= $(BONUS_FUNC:%.c=./output/%.o)
BONUS_TYPES_OBJS	= $(BONUS_TYPES_FUNC:%.c=./output/%.o)
FLAGS				= -Wall -Wextra -Werror
CC					= cc -g

all						:	output $(NAME)

output					:
							@if [ ! -d output ]; then\
								mkdir output; \
							fi

./output/%.o			:	./functions/%.c
							$(CC) $(FLAGS) -c $< -o $@

./output/%.o			:	./bonus/%.c
							$(CC) $(FLAGS) -c $< -o $@

./output/%.o			:	./bonus/types/%.c
							$(CC) $(FLAGS) -c $< -o $@

$(SRC_OBJ)				:
							$(CC) $(FLAGS) -c ft_printf.c -o $@

$(NAME)					:	clean_b $(OBJS) $(SRC_OBJ)
							ar rcs $@ $(OBJS) $(SRC_OBJ)

bonus					:	output clean_m clean_lib $(BONUS_TYPES_OBJS) $(BONUS_OBJS) $(SRC_OBJ)
							ar -rcs $(NAME) $(BONUS_TYPES_OBJS) $(BONUS_OBJS) $(SRC_OBJ)

clean_m					:
							@rm -rf $(OBJS)
			
clean_b					:
							@rm -rf $(BONUS_OBJS) $(BONUS_TYPES_OBJS)

clean_lib				:
							@rm -rf $(NAME)

clean					:	clean_m clean_b	
							@rm -rf $(SRC_OBJ)

fclean					: clean clean_lib

re						: fclean all
.PHONY					: all clean clean_b clean_m fclean bonus re $(NAME)
