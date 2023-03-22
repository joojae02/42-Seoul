CC = cc
CFLAGS = -Wall -Wextra -Werror
# SRCS = *.c
SRCS = $(wildcard ft_*.c)
OBJECTS = $(SRCS:.c=.o)
NAME = libft.a

all : $(NAME) 
$(NAME) : $(OBJECTS)
	ar -cr  $(NAME) $(OBJECTS)
.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}
clean :
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
