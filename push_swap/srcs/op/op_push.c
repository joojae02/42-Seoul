/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:49:26 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/10/12 17:49:27 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../push_swap.h"

void	pa(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_b < 1)
		return ;
	tmp = stack->top_b;
	if (stack->size_b > 1)
	{
		stack->top_b = stack->top_b->next;
		stack->top_b->prev = NULL;
	}
	if (stack->size_a == 0)
	{
		tmp->next = NULL;
		stack->top_a = tmp;
		stack->bottom_a = tmp;
	}
	else
	{
		tmp->next = stack->top_a;
		stack->top_a->prev = tmp;
		stack->top_a = tmp;
	}
	stack->size_a += 1;
	stack->size_b -= 1;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size_a < 1)
		return ;
	tmp = stack->top_a;
	if (stack->size_a > 1)
	{
		stack->top_a = stack->top_a->next;
		stack->top_a->prev = NULL;
	}
	if (stack->size_b == 0)
	{
		tmp->next = NULL;
		stack->top_b = tmp;
		stack->bottom_b = tmp;
	}
	else
	{
		tmp->next = stack->top_b;
		stack->top_b->prev = tmp;
		stack->top_b = tmp;
	}
	stack->size_a -= 1;
	stack->size_b += 1;
	write(1, "pb\n", 3);
}
