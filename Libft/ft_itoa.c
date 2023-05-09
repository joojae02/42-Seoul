/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:31:03 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/05/09 18:31:04 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int count_digit(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	else if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		num_digit;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num_digit = count_digit(n);
	result = (char *)malloc(sizeof(char) * (num_digit + 1));
	if (!result)
		return (0);
	result[num_digit--] = '\0'; 
	if (n < 0)
	{
		result[0] = '-';
		n = -n;
	}
	while (n != 0)
	{
		result[num_digit] = n%10;
		n /= 10;
		num_digit--;
	}
	return (result);
}