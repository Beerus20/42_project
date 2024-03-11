.SILENT :
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

watch		:
				@watch -n 0.2 -t make all

all			: build-lib
				$(CC) $(FLAGS) main.c -L$(LIBPATH) $(LIBNAME) && ./a.out

test		:
				$(CD) && ~/francinette/tester.sh || ~/francinette-image/run.sh

build-lib	:
				@$(CD) && make all

norme		:
				$(CD) && make norme

clean		:
				$(CD) && make clean

fclean		:
				$(CD) && make fclean

save		: fclean
				rm -rf a.out && git add . && git commit -m "$(COMMIT)" && git push

.PHONY		: save fclean clean build-lib test all watch
