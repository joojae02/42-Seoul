/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:49:57 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/10/12 18:14:31 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>
#include "../push_swap.h"

int	print_error(int type)
{
	if (type >= 1)
	{
		write(2, "Error\n", 6);
	}
	exit(1);
	return (-1);
}

t_node	*init_node(void)
{
	t_node		*node;

	node = NULL;
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->prev = NULL;
	node->next = NULL;
	node->content = 0;
	return (node);
}

t_stack	*init_stack(void)
{
	t_node		*node_a;
	t_stack		*stack;

	stack = NULL;
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	node_a = init_node();
	stack->array = NULL;
	stack->size_a = 0;
	stack->top_a = node_a;
	stack->bottom_a = node_a;
	stack->size_b = 0;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*next;
	t_node	*node;

	node = stack->top_a;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	free(stack->array);
	free(stack);
}

int	main(int argc, char *argv[])
{
	int			array_size;
	int			*array;
	t_stack		*stack;

	if (argc < 2)
	{
		print_error(-1);
	}
	array_size = 0;
	stack = init_stack();
	array_size = ft_array_size(argc, argv);
	array = ft_set_array(argc, argv, array_size);
	ft_set_stack(stack, array, array_size);
	ft_array_sort(array, array_size, 0);
	stack->array = (int *)array;
	ft_sort(stack);
	free_stack(stack);
	return (0);
}
