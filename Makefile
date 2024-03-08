#	GLOBAL	variable
NAME		= test
LIBPATH		?= ./printf
LIBNAME		?= -lftprintf

#	EXEC	variable
CC			= cc
FLAGS		= -Wall -Wextra -Werror

#	SUPP	variable
CD			= cd $(LIBPATH)
COMMIT		?= ""

watch		: build-lib
				watch -n 0.2 make all

all			:
				$(CC) $(FLAGS) main.c -L$(LIBPATH) $(LIBNAME) && ./a.out

test		:
				$(CD) && ~/francinette/tester.sh

build-lib	:
				$(CD) && make all

norme		:
				$(CD) && make norme

clean		:
				$(CD) && make clean

fclean		:
				$(CD) && make fclean

save		: fclean
				git add . && git commit -m "$(COMMIT)" && git push

.PHONY		: save fclean clean build-lib test all watch
