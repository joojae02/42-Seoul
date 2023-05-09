/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 18:25:55 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/05/09 18:25:56 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	count_char(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			while (s[i] == c && s[i] != '\0')
				i++;
	}
	return (count);
}

void	ft_copy(char const *s, int i, int j, char *into)
{
	int	tmp;

	tmp = 0;
	while (tmp < j)
	{
		into[tmp] = s[i + tmp];
		tmp++;
	}
	into[tmp] = '\0';
}
void	ft_free(char **result, int k)
{
	while (k >= 0)
	{
		free(result[k]);
		k--;
	}
}
char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	**result;

	size = count_char(s, c);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (!result)
		return (0);
	i = -1;
	k = 0;
	while (s[++i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = 0;
		while (s[i + j] != '\0' && s[i + j] != c)
			j++;
		if (j != 0)
		{
			result[k] = (char *)malloc(sizeof(char) * (j + 1));
			if (!result[k])
			{
				ft_free(result, k);
				free(result);
				return (0);
			}
			ft_copy(s, i, j, result[k]);
			k++;
		}
		i += j;
	}
	result[k] = NULL;
	return (result);
}
