#include "../../libft/libft.h"
#include "../../push_swap.h"

void	sa(t_stack *stack)
{
	int	tmp;

	if (stack->size_a < 2)
	{
		return ;
	}
	tmp = stack->top_a->content;
	stack->top_a->content = stack->top_a->next->content;
	stack->top_a->next->content = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	int	tmp;

	if (stack->size_b < 2)
	{
		return ;
	}
	tmp = stack->top_b->content;
	stack->top_b->content = stack->top_b->next->content;
	stack->top_b->next->content = tmp;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	int	tmp;

	if (stack->size_a < 2)
	{
		return ;
	}
	if (stack->size_b < 2)
	{
		return ;
	}
	tmp = stack->top_a->content;
	stack->top_a->content = stack->top_a->next->content;
	stack->top_a->next->content = tmp;
	tmp = stack->top_b->content;
	stack->top_b->content = stack->top_b->next->content;
	stack->top_b->next->content = tmp;
	write(1, "ss\n", 3);
}
