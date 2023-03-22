/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:09:07 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/22 18:58:04 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*stock_list;
	int			i;
	int			j;

	stock_list = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!stock_list)
		return (0);
	i = 0;
	while (i < ac)
	{
		stock_list[i].size = ft_strlen(av[i]);
		stock_list[i].str = av[i];
		stock_list[i].copy = (char *)malloc(sizeof(char)
				* (ft_strlen(av[i]) + 1));
		j = 0;
		while (av[i][j] != '\0')
		{
			stock_list[i].copy[j] = av[i][j];
			j++;
		}
		stock_list[i].copy[stock_list[i].size] = '\0';
		i++;
	}
	stock_list[ac].str = 0;
	return (stock_list);
}
