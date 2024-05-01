all:
	@cd ft_printf && make all
	@gcc -Wall -Wextra -Werror server.c ft_printf/libftprintf.a -o server
	@gcc -Wall -Wextra -Werror client.c ft_printf/libftprintf.a -o client

clean:
	@cd ft_printf && make clean
	@rm -rf server
	@rm -rf client

fclean: clean
	@cd ft_printf && make fclean

re: fclean all

.PHONY: all clean fclean re