/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:20:17 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/21 12:26:03 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_get_total_size(int size, char **strs, char *sep)
{
	int	total_size;
	int	i;
	int	sep_size;

	total_size = 0;
	sep_size = ft_strlen(sep);
	i = -1;
	while (++i < size)
	{
		total_size += ft_strlen(strs[i]);
		if (i != size -1)
			total_size += sep_size;
	}
	return (total_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_size;
	int		i;
	int		j;
	int		start;

	total_size = ft_get_total_size(size, strs, sep);
	result = (char *)malloc(sizeof(char) * (total_size + 1));
	i = -1;
	start = -1;
	while (++i < size)
	{
		j = -1;
		while (strs[i][++j] != '\0')
			result[++start] = strs[i][j];
		j = -1;
		while (sep[++j] != '\0' && i != size - 1)
			result[++start] = sep[j];
	}
	result[start + 1] = '\0';
	return (result);
}
