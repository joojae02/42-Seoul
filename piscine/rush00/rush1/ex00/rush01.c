/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosekim <bosekim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:46:23 by bosekim           #+#    #+#             */
/*   Updated: 2023/02/19 17:06:49 by bosekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include<stdio.h>
void	rush01_dfs(int arr[][6], int depth);
void	print_field(int arr[][6]);
int		check_only(int arr[][6], int depth, int height);
int		check_score(int arr[][6]);

int	check_only(int arr[][6], int depth, int height)
{
	int	check_x;
	int	check_y;

	check_x = 1;
	check_y = 1;
	while (check_x <= 4)
	{
		if (arr[depth / 4 + 1][check_x] == height)
			return (1);
		check_x = check_x + 1;
	}
	while (check_y <= 4)
	{
		if (arr[check_y][depth % 4 + 1] == height)
			return (1);
		check_y = check_y + 1;
	}
	return (0);
}
void	print_field(int arr[][6])
{
	int		i;
	char 	height;
	
	i = 0;
	while (i < 16)
	{
		height = '0' + arr[i / 4 + 1][i % 4 + 1];
		write(1, &height, 1);
		if (i % 4 == 3)
			write(1, "\n", 1);
		i = i + 1;
	}
}

void	rush01_dfs(int arr[][6], int depth)
{
	int	height;

	height = 0;
	if (depth == 16)
	{
		if(check_score(arr))
			print_field(arr);
		return ;
	}
	while (++height < 5)
	{
		if(check_only(arr, depth, height))
			continue ;
		arr[depth / 4 + 1][depth % 4 + 1] = height;
		rush01_dfs(arr, depth + 1);
		arr[depth / 4 + 1][depth % 4 + 1] = 0;
	}
}
