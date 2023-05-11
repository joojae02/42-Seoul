/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosekim <bosekim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:40:32 by bosekim           #+#    #+#             */
/*   Updated: 2023/02/19 17:19:32 by bosekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_score(int arr[][6]);
int	check_score_colup(int arr[][6], int x, int y);
int	check_score_coldown(int arr[][6], int x, int y);
int check_score_rowleft(int arr[][6], int x, int y);
int	check_score_rowright(int arr[][6], int x, int y);

int check_score_colup(int arr[][6], int x, int y)
{
	int	height;
	int score;
	
	while (x <= 4)
	{
		height = 0;
		score = 0;
		y = 1;
		while (y <= 4)
		{
			if (height < arr[y][x])
			{
				height = arr[y][x];
				score++;
			}
			y++;
		}
		if (score != arr[0][x])
			return (1);
		x++;
	}
	return (0);	
}

int check_score_coldown(int arr[][6], int x, int y)
{
	int	height;
	int score;
	
	while (x <= 4)
	{
		height = 0;
		score = 0;
		y = 4;
		while (y >= 1)
		{
			if (height < arr[y][x])
			{
				height = arr[y][x];
				score++;
			}
			y--;
		}
		if (score != arr[5][x])
			return (1);
		x++;
	}
	return (0);	
}

int check_score_rowleft(int arr[][6], int x, int y)
{
	int	height;
	int score;
	
	while (y <= 4)
	{
		height = 0;
		score = 0;
		x = 1;
		while (x <= 4)
		{
			if (height < arr[y][x])
			{
				height = arr[y][x];
				score++;
			}
			x++;
		}
		if (score != arr[y][0])
			return (1);
		y++;
	}
	return (0);	
}

int check_score_rowright(int arr[][6], int x, int y)
{
	int	height;
	int score;
	
	while (y <= 4)
	{
		height = 0;
		score = 0;
		x = 4;
		while (x >= 1)
		{
			if (height < arr[y][x])
			{
				height = arr[y][x];
				score++;
			}
			x--;
		}
		if (score != arr[y][5])
			return (1);
		y++;
	}
	return (0);	
}

int check_score(int arr[][6])
{
	if(check_score_colup(arr, 1, 1))
		return (0);
	if(check_score_coldown(arr, 1, 1))
		return (0);
	if(check_score_rowleft(arr, 1, 1))
		return (0);
	if(check_score_rowright(arr, 1, 1))
		return (0);
	return (1);
}
