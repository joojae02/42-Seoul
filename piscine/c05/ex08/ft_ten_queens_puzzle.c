/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:13:48 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/19 14:42:45 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	promising(int *board, int row)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[row] == board[i] || row + board[row] == board[i] + i
			|| row - board[row] == i - board[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_ten_queen(int *board, int row, int *count)
{
	int	col;
	int	c;

	if (row == 10)
	{
		*count += 1;
		col = -1;
		while (++col < 10)
		{
			c = board[col] + '0';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
	else
	{
		col = -1;
		while (++col < 10)
		{
			board[row] = col;
			if (promising(board, row))
				ft_ten_queen(board, row + 1, count);
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	count;
	int	board[10];

	count = 0;
	ft_ten_queen(board, 0, &count);
	return (count);
}
