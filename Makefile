.SILENT :
#	GLOBAL	variable
NAME		= test
LIBPATH		?= ./ft_printf
LIBNAME		?= -lftprintf

#	EXEC	variable
CC			= cc
FLAGS		= -Wall -Wextra -Werror

#	SUPP	variable
CD			= cd $(LIBPATH)
COMMIT		?= ""
N			?= ""

watch		:
				@watch -n 0.5 -t make all

all			: build-lib
				$(CC) $(FLAGS) main.c -L$(LIBPATH) $(LIBNAME) && ./a.out

test		:
				$(CD) && cd ft_printf_tester && sh test $(N)

test-s		:
				$(CD) && cd ft_printf_tester && sh test m && rm -rf myleaks.txt

test-sa		:
				$(CD) && cd ft_printf_tester && sh test && rm -rf myleaks.txt

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
