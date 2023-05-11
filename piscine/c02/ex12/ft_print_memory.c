/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:05:53 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/13 12:52:33 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	set_base(char *hex)
{
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
}

void	print_addr(unsigned long long addr, char *hex, int cnt)
{
	unsigned int	i;

	i = 0;
	if (cnt < 16)
	{
		print_addr(addr / 16, hex, cnt + 1);
		write(1, &hex[addr % 16], 1);
	}
}

void	print_hex(char c, char *hex)
{
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			hex[16];
	unsigned int	i;

	i = -1;
	if (size == 0)
		return (addr);
	set_base(hex);
	print_addr((unsigned long long)addr, hex, 0);
	write(1, ": ", 2);
	while (*((char *)addr + ++i) != '\0' && i < size)
	{
		print_hex(*((char *)addr + i), hex);
		print_hex(*((char *)addr + ++i), hex);
		write(1, " ", 1);
	}
	i = -1;
	while (*((char *)addr + ++i) != '\0' && i < size)
	{
		if (*((char *)addr + i) <= 31 || *((char *)addr + i) == 127)
			write(1, ".", 1);
		else
			write(1, ((char *)addr + i), 1);
	}
	write(1, "\n", 1);
	return (addr);
}
