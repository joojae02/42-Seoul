/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:56:19 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/10/12 17:56:20 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_instructions(t_instruction *instructions)
{
	t_instruction	*next;

	while (instructions)
	{
		next = instructions->next;
		free(instructions->line);
		free(instructions);
		instructions = next;
	}
}

void	execute_instructions(t_instruction *instr,	\
	t_stack *stack_a, t_stack *stack_b)
{
	while (instr)
	{
		if (!ft_strcmp(instr->line, "sa") || !ft_strcmp(instr->line, "ss"))
			swap_stack(stack_a);
		if (!ft_strcmp(instr->line, "sb") || !ft_strcmp(instr->line, "ss"))
			swap_stack(stack_b);
		if (!ft_strcmp(instr->line, "pa"))
			push_stack(stack_a, stack_b);
		if (!ft_strcmp(instr->line, "pb"))
			push_stack(stack_b, stack_a);
		if (!ft_strcmp(instr->line, "ra") || !ft_strcmp(instr->line, "rr"))
			rotate_stack(stack_a);
		if (!ft_strcmp(instr->line, "rb") || !ft_strcmp(instr->line, "rr"))
			rotate_stack(stack_b);
		if (!ft_strcmp(instr->line, "rra") || !ft_strcmp(instr->line, "rrr"))
			reverse_rotate_stack(stack_a);
		if (!ft_strcmp(instr->line, "rrb") || !ft_strcmp(instr->line, "rrr"))
			reverse_rotate_stack(stack_b);
		instr = instr->next;
	}
}

int	add_instruction(t_instruction **instructions, char *line)
{
	t_instruction	*tmp;
	t_instruction	*new;

	new = malloc(sizeof(t_instruction));
	if (!new)
		return (1);
	new->line = ft_strdup(line);
	new->next = NULL;
	tmp = *instructions;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (tmp)
		tmp->next = new;
	else
		*instructions = new;
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	while (n--)
	{
		tmp = (char *)s;
		*tmp = 0;
		s++;
	}
}

int	get_instruction(t_instruction **instructions)
{
	int		ret;
	char	line[4];

	ft_bzero(line, 4);
	ret = read(STDIN_FILENO, line, 3);
	if (ret <= 0)
		return (ret);
	if (line[2] != '\n')
	{
		if (line[0] == '\n' || line[1] == '\n')
			return (-1);
		if (read(STDIN_FILENO, line + 3, 1) < 0 || line[3] != '\n')
			return (-1);
		line[3] = '\0';
	}
	else
		line[2] = '\0';
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb") && \
	ft_strcmp(line, "ss") && ft_strcmp(line, "pa") && ft_strcmp(line, "pb") && \
	ft_strcmp(line, "ra") && ft_strcmp(line, "rb") && ft_strcmp(line, "rr") && \
	ft_strcmp(line, "rra") && ft_strcmp(line, "rrb") && ft_strcmp(line, "rrr"))
		return (-1);
	if (add_instruction(instructions, line))
		return (-1);
	return (1);
}
