all:
	@cd ft_printf && make all
	@gcc -Wall -Wextra -Werror server.c ft_printf/libftprintf.a -o server
	@gcc -Wall -Wextra -Werror client.c ft_printf/libftprintf.a -o client

clean:
	@cd ft_printf && make clean
	@rm -f server
	@rm -f client

fclean: clean
	@cd ft_printf && make fclean

re: fclean all
