/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:00:24 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/12 11:42:42 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i] != '\0')
	{
		if (check == 0)
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				str[i] -= 32;
				check = 1;
			}
		}
		if (str[i] < '0' || (str[i] > '9' && str[i] < 'A') || str[i] > 'z')
			check = 0;
		else
			check = 1;
		i++;
	}
	return (str);
}
