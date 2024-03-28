.SILENT :
./output/%.o		: ./function/%.c
						@$(CC) $(CFLAGS) -o $@ -c $<

./output/%.o		: ./src/%.c
						@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)				: $(SUPP_FUNCT_OBJS) $(FTPRINTF_OBJS)
						@ar rc $(NAME) $^

norme				:
						norminette includes/* function/* src/*

clean 				:
						$(RM) $(SUPP_FUNCT_OBJS) $(FTPRINTF_OBJS) a.out

fclean				: clean
						$(RM) $(NAME)

cleanall			: fclean vimclean
re					: fclean all
.PHONY				: fclean clean all bonus re
