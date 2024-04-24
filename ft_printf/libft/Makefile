NAME = "libft.a"

all:
	@gcc -c -Wall -Wextra -Werror ft_[!l]*.c
	@ar rcs libft.a *.o
	
clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
