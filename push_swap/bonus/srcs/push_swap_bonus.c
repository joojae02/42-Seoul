/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:56:22 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/10/12 17:56:23 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_stack_ordered(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->array[i] >= stack->array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	stack_contains(t_stack *stack, int num)
{
	size_t	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->array[i++] == num)
			return (1);
	}
	return (0);
}

int	init_instructions(t_program *prg)
{
	int			ret;
	char		buff[1];

	prg->instr = NULL;
	ret = get_instruction(&prg->instr);
	while (ret > 0)
		ret = get_instruction(&prg->instr);
	if (ret < 0)
	{
		buff[0] = ' ';
		while (buff[0] && read(STDIN_FILENO, &buff, 1))
			;
		free_instructions(prg->instr);
		free(prg->stack_a.array);
		free(prg->stack_b.array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	malloc_stack(t_stack *stack_a, t_stack *stack_b, size_t stack_size)
{
	stack_a->array = malloc(sizeof(int) * stack_size);
	if (!(stack_a->array))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	stack_b->array = malloc(sizeof(int) * stack_size);
	if (!(stack_b->array))
	{
		free(stack_a->array);
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_program		prg;

	if (--argc < 1)
		return (0);
	if (init_stacks(argc, &argv[1], &prg.stack_a, &prg.stack_b))
		return (1);
	if (init_instructions(&prg))
		return (1);
	execute_instructions(prg.instr, &prg.stack_a, &prg.stack_b);
	if (is_stack_ordered(&prg.stack_a) || prg.stack_b.size)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
	return (free_prg(&prg));
}
