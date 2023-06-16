/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:25:18 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/03/18 17:25:19 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dst;
	unsigned const char	*s;
	size_t				i;

	if (dest == src)
		return (dest);
	i = 0;
	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dst <= s)
	{
		while (i < len)
		{
			dst[i] = s[i];
			i++;
		}
	}
	else
		while (len-- > 0)
			dst[len] = s[len];
	return (dst);
}
