/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:33:46 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/12 11:20:25 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	change(char c, char *str)
{
	char	hex[16];

	hex[0] = '0';
	hex[1] = '1';
	hex[2] = '2';
	hex[3] = '3';
	hex[4] = '4';
	hex[5] = '5';
	hex[6] = '6';
	hex[7] = '7';
	hex[8] = '8';
	hex[9] = '9';
	hex[10] = 'a';
	hex[11] = 'b';
	hex[12] = 'c';
	hex[13] = 'd';
	hex[14] = 'e';
	hex[15] = 'f';
	str[0] = hex[c / 16];
	str[1] = hex[c % 16];
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex[2];

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 31 || str[i] == 127)
		{
			write(1, "\\", 1);
			change(str[i], hex);
			write(1, &hex[0], 1);
			write(1, &hex[1], 1);
		}
		else
		{
			write(1, &str[i], 1);
		}
		i++;
	}
}
