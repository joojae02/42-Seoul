/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 02:20:42 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/03/02 02:20:44 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_convert(t_bsq *f_b, char **map)
{
	int	**int_map;
	int	i;
	int	j;

	int_map = (int **)malloc(sizeof(int *) * f_b->row);
	i = -1;
	while (++i < f_b->row)
		int_map[i] = (int *)malloc(sizeof(int) * f_b->col);
	i = -1;
	while (++i < f_b->row)
	{
		j = -1;
		while (++j < f_b->col)
		{
			if (map[i][j] == f_b->empty)
				int_map[i][j] = 1;
			if (map[i][j] == f_b->obstacle)
				int_map[i][j] = 0;
			if (map[i][j] == f_b->full)
				int_map[i][j] = -1;
		}
	}
	ft_solve(f_b, int_map, map, 0);
}

int	get_min(int a, int b, int c)
{	
	if (a < b)
		b = a;
	if (b < c)
		c = b;
	return (c + 1);
}

int	**fill_square(int *where, int **max_store, int max, int full)
{
	int	i;
	int	j;

	i = where[1] - max + 1;
	while (i <= where[1])
	{
		j = where[0] - max + 1;
		while (j <= where[0])
		{
			max_store[i][j] = full;
			j++;
		}
		i++;
	}
	return (max_store);
}

void	ft_put_map(int **int_map, char **map, t_bsq *f_b)
{
	int	i;
	int	j;

	i = 0;
	while (i < f_b->row)
	{
		j = 0;
		while (j < f_b->col)
		{
			if (int_map[i][j] == -1)
				map[i][j] = f_b->full;
			j++;
		}
		i++;
	}
	j = -1;
	while (++j < f_b->col)
		free(int_map[j]);
	free(int_map);
	ft_print_map(map, f_b);
}

void	ft_solve(t_bsq *f_b, int **int_map, char **map, int max)
{
	int	j;
	int	i;
	int	where[2];

	i = -1;
	while (++i < f_b->row)
	{
		j = -1;
		while (++j < f_b->col)
		{
			if (map[i][j] == f_b->empty && (i > 0 && j > 0))
				int_map[i][j] = get_min(int_map[i -1][j -1],
						int_map[i -1][j], int_map[i][j -1]);
			if (max < int_map[i][j])
			{
				where[0] = j;
				where[1] = i;
				max = int_map[i][j];
			}
		}
	}
	int_map = fill_square(where, int_map, max, -1);
	ft_put_map(int_map, map, f_b);
}
