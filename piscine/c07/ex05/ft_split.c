/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:06:33 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/22 14:28:29 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	is_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_charset(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (is_charset(charset, str[i]) == 0
			&& (is_charset(charset, str[i + 1]) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	ft_copy(char *str, int i, int j, char *into)
{
	int	tmp;

	tmp = 0;
	while (tmp < j)
	{
		into[tmp] = str[i + tmp];
		tmp++;
	}
	into[tmp] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		size;
	char	**result;

	size = count_charset(str, charset);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	i = -1;
	size = -1;
	while (str[++i] != '\0')
	{
		if (is_charset(charset, str[i]) == 0)
		{
			j = 0;
			while (str[i + j] != '\0'
				&& is_charset(charset, str[i + j]) == 0)
				j++;
			result[++size] = (char *)malloc(sizeof(char) * (j + 1));
			ft_copy(str, i, j, result[size]);
			i += j;
		}
	}
	result[size + 1] = 0;
	return (result);
}
