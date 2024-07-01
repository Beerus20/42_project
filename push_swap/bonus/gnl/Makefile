NAME			= libgnl.a
FILES			= get_next_line.c get_next_line_utils.c
OBJS			= $(FILES:%.c=output/%.o)
CFLAGS			= -Wall -Wextra -Werror
CC				= cc

all				: $(NAME)

output			:
					@if [ ! -d output ]; then\
						mkdir output; \
					fi

output/%.o		: %.c | output
					$(CC) $(CFLAGS) -c $< -o $@

$(NAME)			: $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $@

clean			:
					rm -rf $(OBJS)

fclean			: clean
					rm -rf $(NAME)

re				: fclean

.PHONY			: all clean fclean re

