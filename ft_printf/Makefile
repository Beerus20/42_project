NAME				= libftprintf.a
MANDATORY			= ./mandatory
BONUS				= ./bonus

all					: $(NAME)

$(NAME)				:
ifeq ($(shell [ -d $(NAME) ] && echo true), true)
	rm -rf $(NAME)
endif
						@cd $(MANDATORY) && make all					

norme				:
						norminette includes/* function/* src/*

bonus				:
ifeq ($(shell [ -d $(NAME) ] && echo true), true)
	rm -rf $(NAME)
endif
						@cd $(BONUS) && make all

norme				:
						@cd $(MANDATORY) && make norme
						@cd $(BONUS)	&& make norme

clean 				:
						@cd $(MANDATORY) && make clean
						@cd $(BONUS)	&& make clean

fclean				: clean
						$(RM) $(NAME)

re					: fclean all
.PHONY				: fclean clean all bonus re $(NAME)	
