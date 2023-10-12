/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:46:07 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/22 14:11:49 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);

int	ft_get_nbr_size(long nbr, int size)
{
	int	nbr_size;

	nbr_size = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		nbr_size++;
	}
	while (nbr / size != 0)
	{
		nbr /= size;
		nbr_size++;
	}
	return (nbr_size);
}

char	*ft_reverse(char *str)
{
	int		i;
	int		len;
	char	tmp;
	int		check;

	check = 0;
	if (str[0] == '-')
		check++;
	len = 0;
	while (str[len] != '\0')
		len++;
	i = 0;
	while (i < len / 2)
	{
		tmp = str[i + check];
		str[i + check] = str[len - i - 1];
		str[len - i - 1] = tmp;
		i++;
	}
	return (str);
}

void	ft_putnbr(long nbr, char *base, char *result, int nbr_size)
{
	int	size;

	size = 0;
	while (base[size] != '\0')
		size++;
	if (nbr < 0)
	{
		result[nbr_size] = '-';
		ft_putnbr(-nbr, base, result, nbr_size + 1);
	}
	else
	{
		if (nbr / size != 0)
			ft_putnbr(nbr / size, base, result, nbr_size + 1);
		result[nbr_size] = base[nbr % size];
	}
}

char	*ft_putnbr_base(int nbr, char *base, char *result)
{
	int	i;
	int	j;
	int	nbr_size;

	i = -1;
	while (base[++i] != '\0')
		if (base[i] == '+' || base[i] == '-')
			return (0);
	if (i == 0 || i == 1)
		return (0);
	i = -1;
	while (base[++i] != '\0')
	{
		j = 0;
		while (base[i + ++j] != '\0')
			if (base[i] == base[i + j])
				return (0);
	}
	nbr_size = ft_get_nbr_size(nbr, i);
	result = (char *)malloc(sizeof(char) * (nbr_size + 1));
	if (!result)
		return (0);
	ft_putnbr(nbr, base, result, 0);
	result[nbr_size] = '\0';
	return (ft_reverse(result));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		int_nbr;
	char	*result;

	result = 0;
	int_nbr = ft_atoi_base(nbr, base_from);
	if (int_nbr == -1)
		return (0);
	result = ft_putnbr_base(int_nbr, base_to, result);
	if (result == 0)
		return (0);
	return (result);
}
