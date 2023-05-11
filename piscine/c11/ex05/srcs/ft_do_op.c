/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:14:24 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/27 15:48:50 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		ft_atoi(char *str);
int		ft_do_op(int first, char *op, int second);
void	ft_putnbr(int nb);

int	ft_do_op(int first, char *op, int second)
{
	if (!(*op == '+' || *op == '-' || *op == '*'
			|| *op == '/' || *op == '%') || op[1] != '\0')
		return (0);
	if (*op == '+')
		return (first + second);
	else if (*op == '-')
		return (first - second);
	else if (*op == '*')
		return (first * second);
	else if (*op == '/')
	{
		if (second == 0)
			write(1, "Stop : division by zero\n", 25);
		else
			return (first / second);
	}
	else if (*op == '%')
	{
		if (second == 0)
			write(1, "Stop : modulo by zero\n", 22);
		else
			return (first % second);
	}
	return (-1);
}
