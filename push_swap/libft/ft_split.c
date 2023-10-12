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

static int	count_char(char const *s, char c)
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

static char	*word_malloc(const char *s, char c)
{
	int		i;
	char	*result;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		result[i] = s[i];
		i++;
	}
	result[i] = 0;
	return (result);
}

static char	**ft_free(char **result, int k)
{
	while (k >= 0)
	{
		free(result[k]);
		k--;
	}
	free(result);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**result;

	result = (char **)malloc(sizeof(char *) * (count_char(s, c) + 1));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i])
		{
			result[j] = word_malloc(s + i, c);
			if (!result[j])
				return (ft_free(result, j - 1));
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	result[j] = NULL;
	return (result);
}
