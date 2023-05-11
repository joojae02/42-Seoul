/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:32:13 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/16 11:37:49 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr(long nbr, char *base, int size)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nbr, base, size);
	}
	else
	{
		if (nbr / size != 0)
		{
			ft_putnbr(nbr / size, base, size);
		}
		write(1, &base[nbr % size], 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return ;
		i++;
	}
	if (i == 0 || i == 1)
		return ;
	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[i + ++j] != '\0')
			if (base[i] == base[i + j])
				return ;
		i++;
	}
	ft_putnbr(nbr, base, i);
}
