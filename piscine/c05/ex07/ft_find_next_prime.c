/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:12:01 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/19 15:06:20 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long	i;

	if (nb <= 0 || nb == 1)
		return (0);
	i = 2;
	while (i * i <= (long)nb)
	{
		if ((long)nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (1)
	{
		if (ft_is_prime(nb))
			break ;
		nb++;
	}
	return (nb);
}
