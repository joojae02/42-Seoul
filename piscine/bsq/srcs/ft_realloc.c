/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 22:16:35 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/03/01 22:16:37 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_strlen(char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned int	i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)b;
	while (i < len)
	{
		*p = (unsigned char)c;
		p++;
		i++;
	}
	return (b);
}

void	*ft_memcpy(void *dst, void *src, unsigned int n)
{
	unsigned int	i;
	char			*csrc;
	char			*cdst;

	i = 0;
	csrc = (char *)src;
	cdst = (char *)dst;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	cdst[i] = 0;
	return (dst);
}

void	*ft_realloc(void *ptr, unsigned int size)
{
	void	*nptr;

	if (size == 0)
	{
		free(ptr);
		return (0);
	}
	if ((unsigned int)ft_strlen((char *)ptr) >= size)
		return (ptr);
	nptr = malloc(size);
	if (nptr == 0)
		return (0);
	ft_memset(nptr, 0, size);
	nptr = ft_memcpy(nptr, ptr, size);
	free(ptr);
	return (nptr);
}

void	ft_free(t_bsq *f_b, char **map, char *buff, char *result)
{
	int	i;

	if (buff != 0)
		free(buff);
	if (result != 0)
		free(result);
	if (map != 0)
	{
		i = 0;
		while (i < f_b->row)
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	f_b->row = 0;
	f_b->col = 0;
	f_b->empty = 0;
	f_b->obstacle = 0;
	f_b->full = 0;
}
