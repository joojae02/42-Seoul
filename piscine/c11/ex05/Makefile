CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c ft_atoi.c ft_do_op.c ft_putnbr.c
SR = ./srcs/
SRCS = $(addprefix $(SR), $(SRC))
OBJECTS = $(SRCS:.c=.o)
NAME = do-op

all : $(NAME)
$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)
.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
clean :
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
