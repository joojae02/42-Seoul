/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosekim <bosekim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 14:36:10 by bosekim           #+#    #+#             */
/*   Updated: 2023/02/19 16:33:18 by bosekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

void	rush01_dfs(int arr[][6], int depth);
int		convert_argv(int arr[][6], char *str);
char	*start_zero(int arr[][6], char *str, int *flag, int *a_i);

char	*start_zero(int arr[][6], char *str, int *flag, int *a_i)
{
	int	result;

	result = 0;
	while (!result && *str <= '4' && *str >= '0')
	{
		if (*str != '0')
			result = *str - '0';
		str = str + 1;
	}
	if (*a_i < 4)
		arr[0][*a_i % 4 + 1] = result;
	else if (*a_i < 8)
		arr[5][*a_i % 4 + 1] = result;
	else if (*a_i < 12)
		arr[*a_i % 4 + 1][0] = result;
	else
		arr[*a_i % 4 + 1][5] = result;
	*flag = 0;
	*a_i = *a_i + 1;
	if(!result)
		*a_i = 17;
	return (str);
}	

int	convert_argv(int arr[][6], char *str)
{
	int	flag;
	int a_i;

	flag = 1;
	a_i = 0;
	while (*str)
	{
		if(*str == ' ' || *str == '\t' || *str == '\n')
		{
			flag = 1;
			str = str + 1;
		}
		else if(*str == '\\' || *str == '!' || *str == '$')
			return (0);
		else if(flag && *str >='0' && *str <= '9')
			str = start_zero(arr, str, &flag, &a_i);
		else
			return (0);
	}
	if(a_i != 16)
		return (0);
	return (1);
}
#include<stdio.h>
int	main(int argc, char *argv[])
{
	int	field[6][6];
	int	init_idx;
	
	init_idx = -1;
	while (++init_idx < 36)
		field[init_idx / 6][init_idx % 6] = 0;
	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (!convert_argv(field,argv[1]))
	{
		write(1, "error\n", 6);
		return (0);
	}
	rush01_dfs(field,0);
}
