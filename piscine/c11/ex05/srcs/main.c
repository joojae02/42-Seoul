/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:13:05 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/27 15:49:06 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int		ft_atoi(char *str);
int		ft_do_op(int first, char *op, int second);
void	ft_putnbr(int nb);

int	main(int argc, char *argv[])
{
	int	first;
	int	second;
	int	result;

	if (argc != 4)
		return (0);
	first = ft_atoi(argv[1]);
	second = ft_atoi(argv[3]);
	result = ft_do_op(first, argv[2], second);
	if (result != -1)
	{
		ft_putnbr(result);
		write(1, "\n", 1);
	}
}
