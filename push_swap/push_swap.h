/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:49:05 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/10/12 17:49:06 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				content;
}			t_node;

typedef struct s_stack
{
	int				*array;
	int				size_a;
	struct s_node	*top_a;
	struct s_node	*bottom_a;
	int				size_b;
	struct s_node	*top_b;
	struct s_node	*bottom_b;
}			t_stack;

int			print_error(int type);
t_node		*init_node(void);
t_stack		*init_stack(void);
void		free_stack(t_stack *stack);
int			main(int argc, char *argv[]);

int			ft_array_size(int argc, char *argv[]);
int			*ft_set_array(int argc, char *argv[], int array_size);
void		ft_set_stack(t_stack *stack, int *array, int array_size);
void		ft_array_sort(int *array, int array_size, int index);

int			ft_split_size(char **split);
int			ft_isspace(char c);
void		ft_free(char **str);
int			ft_check_atoi(const char *str);

void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);
void		pa(t_stack *stack);
void		pb(t_stack *stack);

void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);

void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);

void		ft_sort_a_three(t_stack *stack);
void		ft_sort_big(t_stack *stack);
void		ft_sort(t_stack *stack);

void		ft_sort_big_last(t_stack *stack);
void		ft_sort_three_part(t_stack *stack, int pivot1, int pivot2);
void		ft_sort_pivot(t_stack *stack);

int			get_min_rotate(int a, int b, int a_rotate, int b_rotate);
int			set_a_rotate(int num, t_stack *stack);
void		set_rotate(t_stack *stack, int *a, int *b);

int			get_stack_min(t_node *stack);
int			set_a_rotate_min(t_stack *stack);
int			get_stack_max(t_node *stack);
int			set_a_rotate_max(t_stack *stack);
int			set_a_rotate_mid(int num, t_stack *stack);

void		ft_rotate_same(t_stack *stack, int *a, int *b);
void		ft_rotate_a(t_stack *stack, int a);
void		ft_rotate_b(t_stack *stack, int b);

#endif
