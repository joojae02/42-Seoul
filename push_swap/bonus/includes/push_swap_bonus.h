#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				*array;
	size_t			size;
}					t_stack;

typedef struct s_instruction
{
	char			*line;
	void			*next;
}					t_instruction;

typedef struct s_program
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_instruction	*instr;
}					t_program;

int					stack_contains(t_stack *stack, int num);
int					malloc_stack(t_stack *stack_a, t_stack *stack_b, \
	size_t stack_size);

int					init_stacks(int argc, char *argv[],	\
	t_stack *stack_a, t_stack *stack_b);

void				reverse_rotate_stack(t_stack *stack);
void				rotate_stack(t_stack *stack);
void				push_stack(t_stack *stack1, t_stack *stack2);
void				swap_stack(t_stack *stack);

void				free_instructions(t_instruction *instructions);
void				execute_instructions(t_instruction *instr,	\
	t_stack *stack_a, t_stack *stack_b);
int					add_instruction(t_instruction **intructions, char *line);
int					get_instruction(t_instruction **instructions);

int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *str);
int					ft_atoi(const char *str, int *num);
int					free_prg(t_program *prg);

#endif
