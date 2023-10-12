NAME = push_swap


LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

CC = cc
CFLAG = -Wall -Wextra -Werror

SRCS		= ./srcs/push_swap.c \
			./srcs/algo/algo_sort.c \
			./srcs/algo/algo_sort_util.c \
			./srcs/algo/algo_rotate.c \
			./srcs/algo/algo_rotate_util.c \
			./srcs/algo/algo_rotate_op.c \
			./srcs/parse/parse_util.c \
			./srcs/parse/parse_array.c \
			./srcs/op/op_push.c \
			./srcs/op/op_reverse_rotate.c \
			./srcs/op/op_rotate.c \
			./srcs/op/op_swap.c \
			
BSRCS		= ./bonus/srcs/push_swap_bonus.c \
			./bonus/srcs/init_stacks.c \
			./bonus/srcs/instructions.c \
			./bonus/srcs/operations.c \
			./bonus/srcs/utils.c \

OBJS		= $(SRCS:%.c=%.o)
BOBJS		= $(BSRCS:%.c=%.o)

.c.o:
	$(CC) $(CFLAG) -c $< -o $@

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAG) $^ -o $@

bonus:
	make fclean -C ./bonus
	make all -C ./bonus

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C ./bonus
	rm -rf $(OBJS)
	rm -rf $(BOBJS)

fclean:	
	make clean
	make fclean -C ./bonus
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)
	
re :
	make fclean
	make all

.PHONY:	all clean fclean re bonus
