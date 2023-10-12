/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:21:29 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/16 11:17:46 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_bsq.h"

int		ft_atoi(char *str);

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	free(str);
	return (sign * result);
}
