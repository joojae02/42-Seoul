#include "../../libft/libft.h"
#include "../../push_swap.h"

void	rra(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_a < 2)
	{
		return ;
	}
	tmp = stack->bottom_a;
	stack->bottom_a = stack->bottom_a->prev;
	stack->bottom_a->next = NULL;
	stack->top_a->prev = tmp;
	tmp->next = stack->top_a;
	stack->top_a = tmp;
	stack->top_a->prev = NULL;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_b < 2)
	{
		return ;
	}
	tmp = stack->bottom_b;
	stack->bottom_b = stack->bottom_b->prev;
	stack->bottom_b->next = NULL;
	stack->top_b->prev = tmp;
	tmp->next = stack->top_b;
	stack->top_b = tmp;
	stack->top_b->prev = NULL;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_b < 2 || stack->size_a < 2)
	{
		return ;
	}
	tmp = stack->bottom_a;
	stack->bottom_a = stack->bottom_a->prev;
	stack->bottom_a->next = NULL;
	stack->top_a->prev = tmp;
	tmp->next = stack->top_a;
	stack->top_a = tmp;
	stack->top_a->prev = NULL;
	tmp = stack->bottom_b;
	stack->bottom_b = stack->bottom_b->prev;
	stack->bottom_b->next = NULL;
	stack->top_b->prev = tmp;
	tmp->next = stack->top_b;
	stack->top_b = tmp;
	stack->top_b->prev = NULL;
	write(1, "rrr\n", 4);
}
