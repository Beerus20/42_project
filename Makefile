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
N			?= ""

watch		:
				@watch -n 0.5 -t make all

all			: build-lib
				$(CC) $(FLAGS) main.c -L$(LIBPATH) $(LIBNAME) && ./a.out

test-%		:
				$(CD) && cd ft_printf_tester && sh test $(subst test-, , $@) && rm -rf myleaks.txt

build-lib	:
				@$(CD) && make all

norme		:
				$(CD) && make norme

clean		:
				$(CD) && make clean

fclean		:
				$(CD) && make fclean

save-%		: fclean
				rm -rf a.out && git add . && git commit -m "$(subst save-, , $@)" && git push

.PHONY		: save fclean clean build-lib test all watch
