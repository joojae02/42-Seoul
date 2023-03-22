/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 04:14:53 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/26 15:49:00 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	asc;
	int	desc;

	i = 1;
	asc = 1;
	desc = 1;
	while (i < length)
	{
		if (f(tab[i - 1], tab[i]) <= 0)
			asc += 1;
		if (f(tab[i - 1], tab[i]) >= 0)
			desc += 1;
		i++;
	}
	if (asc == length || desc == length || length == 0)
		return (1);
	return (0);
}
