/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:42:25 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/09 18:49:09 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_pt(char c)
{
	write(1, &c, 1);
}

void	ft_print(int *a, int n)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < n - 1)
	{
		if (a[i] >= a[i + 1])
			return ;
		i++;
	}
	i = 0;
	while (i < n)
	{
		ft_pt(a[i] + 48);
		if (a[i] == 10 - n + i)
			check++;
		i++;
	}
	if (check != i)
		write(1, ", ", 2);
}

void	ft_print_combn(int n)
{
	int	a[10];
	int	i;

	i = -1;
	while (++i < n)
	{
		a[i] = 0;
	}
	while (a[0] <= 10 - n)
	{	
		ft_print(a, n);
		i = n;
		while (--i > 0)
		{
			if (a[i] <= 9)
			{
				a[i]++;
			}			
			else
			{
				a[i - 1]++;
				a[i] = 0;
			}
		}
	}
}
