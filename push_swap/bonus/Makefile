# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaehyjoo <jaehyjoo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/12 17:56:24 by jaehyjoo          #+#    #+#              #
#    Updated: 2023/10/12 17:56:25 by jaehyjoo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CC_FLAGS	=	-Wall -Wextra -Werror
RM			=	rm -rf
DIR_HEADERS =	./includes/
DIR_SRCS	=	./srcs/
DIR_OBJS	=	./compiled_srcs/

SRC			=	push_swap_bonus.c \
				init_stacks.c \
				operations.c \
				instructions.c \
				utils.c

SRCS		=	$(SRC)
OBJS 		=	$(SRCS:%.c=$(DIR_OBJS)%.o)
NAME 		=	checker

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)

$(OBJS):		| $(DIR_OBJS)

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
				$(CC) $(CC_FLAGS) -I $(DIR_HEADERS) -c $< -o $@

$(DIR_OBJS):
				mkdir $(DIR_OBJS)


clean:
				$(RM) $(DIR_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
