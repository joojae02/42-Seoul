/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:57:21 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/04/29 19:57:21 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	total_len;
	size_t	j;

	total_len = 0;
	i = -1;
	total_len += ft_strlen(s1);
	total_len += ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (total_len + 1));
	if (!new)
		return (NULL);
	while (s1[++i] != '\0')
		new[i] = s1[i];
	j = -1;
	while (s2[++j] != '\0')
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}
