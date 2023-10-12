/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:55:27 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/20 13:46:04 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcheck(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_b(char *str, char *base, int i, int base_size)
{
	int	tmp;

	tmp = 0;
	while (str[i] != '\0' && ft_strcheck(base, str[i]) != -1)
	{
		tmp *= base_size;
		tmp += ft_strcheck(base, str[i]);
		i++;
	}
	return (tmp);
}

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] == '\0')
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == '\n'
			|| base[i] == ' ' || base[i] == '\t' || base[i] == '\f'
			|| base[i] == '\r')
			return (1);
		i++;
	}
	if (i == 0 || i == 1)
		return (1);
	i = -1;
	while (base[++i] != '\0')
	{
		j = 0;
		while (base[i + ++j] != '\0')
			if (base[i] == base[i + j])
				return (1);
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	result;
	int	sign;
	int	base_size;

	if (ft_check(base))
		return (-1);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sign = 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	result = ft_atoi_b(str, base, i, base_size);
	return (result * sign);
}
