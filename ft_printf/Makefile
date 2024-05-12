CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_tool.c ft_tools.c ft_libft.c

NAME = libftprintf.a

AR = ar -rs

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	ar -rs $(NAME) $(OBJS)
clean :
	rm -f $(OBJS)
	
fclean : clean
	rm -f $(NAME)
	
re : fclean all

.PHONY: all clean fclean re