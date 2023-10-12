/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:16:47 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/03/01 22:16:48 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	check_in_f_b(t_bsq *f_b, char c)
{
	if (f_b -> empty == c)
		return (1);
	if (f_b -> obstacle == c)
		return (1);
	if (f_b -> full == c)
		return (1);
	return (0);
}

int	check_same_character(t_bsq *f_b)
{
	if (f_b -> empty == f_b -> obstacle
		|| ((f_b -> empty) <= 31 || (f_b -> empty) == 127))
		return (1);
	if (f_b -> obstacle == f_b -> full
		|| (f_b -> obstacle) <= 31 || (f_b -> obstacle) == 127)
		return (1);
	if (f_b -> full == f_b -> empty
		|| (f_b -> full) <= 31 || (f_b -> full) == 127)
		return (1);
	return (0);
}

int	check_another_character(t_bsq *f_b, char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\n')
		i++;
	while (buff[i] != '\0')
	{
		if (buff[i] != '\n')
		{
			if (!check_in_f_b(f_b, buff[i]))
				return (1);
			if (buff[i] <= 31 || buff[i] == 127)
				return (1);
		}	
		i++;
	}
	return (0);
}

int	check_least_character(t_bsq *f_b, char *buff, int i, int col)
{
	int	check;
	int	count_row;
	int	count_col;

	check = 0;
	count_row = 0;
	count_col = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == f_b->obstacle)
			check++;
		if (buff[i] == '\n')
		{
			count_row++;
			if (col != count_col)
				return (1);
			count_col = 0;
		}
		else
			count_col++;
		i++;
	}
	if (check == 0 || count_row != f_b->row)
		return (1);
	return (0);
}

int	ft_check_all(t_bsq *f_b, char *buff)
{
	int	i;
	int	col;
	int	i_start;

	i = 0;
	col = 0;
	while (buff[i] != '\n')
		i++;
	i_start = i + 1;
	while (buff[i_start + col] != '\n')
		col++;
	if (f_b -> row < 1)
		return (1);
	if (check_same_character(f_b) == 1)
		return (1);
	if (check_another_character(f_b, buff) == 1)
		return (1);
	if (check_least_character(f_b, buff, i + 1, col) == 1)
		return (1);
	return (0);
}
