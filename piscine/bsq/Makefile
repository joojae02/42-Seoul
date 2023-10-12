CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c ft_atoi.c ft_realloc.c ft_check.c ft_strcat.c ft_print.c ft_solve.c 
SR = ./srcs/
SRCS = $(addprefix $(SR), $(SRC))
OBJECTS = $(SRCS:.c=.o)
NAME = bsq

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