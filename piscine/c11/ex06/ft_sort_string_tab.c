/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:21:06 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/26 18:13:43 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	i = -1;
	size = 0;
	while (tab[++i] != 0)
		size++;
	i = 0;
	while (i < size)
	{
		j = 1;
		while (j < size - i)
		{
			if (ft_strcmp(tab[j - 1], tab[j]) > 0)
			{
				tmp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
