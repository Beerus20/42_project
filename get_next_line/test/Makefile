CC		= cc
FLAGS	= -Wall -Wextra -Werror

watch	:
			@watch -n 0.2 make all

all		:
			@$(CC) $(FLAGS) main.c ../*.c && ./a.out

buff-%	:
			@$(CC) $(FLAGS) -D BUFFER_SIZE=$(subst buff-, , $@) main.c && ./a.out

paco\:%	:
			@cd ../fsoares && make &(subst paco:, , $@)
test	: all
			valgrind -s --leak-check=full --track-origins=yes ./a.out

norme	:
			cd .. && norminette *.c *.h
