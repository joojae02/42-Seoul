/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bosekim <bosekim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:46:10 by bosekim           #+#    #+#             */
/*   Updated: 2023/02/18 14:37:40 by bosekim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int	convert_argv(int field[][6], char *str);

int convert_argv(int field[][6], char *str)
{
	int	a_i;
	int	flag;
	int f_i;
	
	a_i = -1;
	flag = 1;
	f_i = 0;
	while (str[++a_i])
	{
		if(str[a_i] == ' ' || str[a_i] == '\t' || str[a_i] == '\n')
			flag = 1;
		else if(str[a_i] == '\\' || str[a_i] == '!' || str[a_i] == '$')
			return (0);
		else if(flag && str[a_i] >='0' && str[a_i] <= '9')
		{
			flag = 0;
			field[f_i / 4 + 1][f_i % 4 + 1] = str[a_i] - '0';
			f_i++;
		}
		else
			return (0);
	}
	if(f_i != 16)
		return (0);
	return (1);
}

int main(int argc, char *argv[])
{	
	int	field[6][6];
	
	for (int f_i = 0; f_i < 36; f_i++)
		field[f_i / 6][f_i % 6] = 0;
	if (argc != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (!convert_argv(field,argv[1]))
	{
		write(1, "error\n",6);
		return (0);
	}
	for (int i = 0;i<36;i++)
	{
		if(!(i%6))
			printf("\n");
		printf("%d ",field[i/6][i%6]);
	}
}
