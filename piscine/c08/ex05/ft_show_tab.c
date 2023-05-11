/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:03:32 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/22 15:03:33 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else
	{
		if (nb / 10 != 0)
		{
			ft_putnbr(nb / 10);
		}
		c = nb % 10 + '0';
		write(1, &c, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i].str != 0)
	{
		j = -1;
		while (par[i].str[++j] != '\0')
			write(1, &par[i].str[j], 1);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		j = -1;
		while (par[i].str[++j] != '\0')
			write(1, &par[i].copy[j], 1);
		write(1, "\n", 1);
		i++;
	}
}
/*
int main(void)
{
	char *av[15] = {"abcd", "abcde", "abcdef", "aaaaaaaa", "bbbbbbbb"};
	t_stock_str *arr = ft_strs_to_tab(5, av);
	ft_show_tab(arr);
}*/