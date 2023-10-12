CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SR = ./srcs/
SRCS = $(addprefix $(SR), $(SRC))
OBJECTS = $(SRCS:.c=.o)
NAME = libft.a
INC = ./includes/
all : $(NAME)
$(NAME) : $(OBJECTS)
	ar -cr  $(NAME) $(OBJECTS)
.c.o :
	$(CC) $(CFLAGS) -c $< -I $(INC) -o ${<:.c=.o}
clean :
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
