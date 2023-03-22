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

#include "libc.h"

void	*ft_memmove(void* dest, const void* src, size_t len)
{
	unsigned char		*dst;
	unsigned const char	*s;
	size_t			i;

	i = -1;
	dst = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dst < s) 
        while (++i < len) 
            dst[i] = s[i]; 
    else 
        while (++i < len) 
            dst[len - 1 - i] = s[len - 1 - i];
    return (dst); 
}