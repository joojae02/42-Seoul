/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:56:23 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/10/12 17:56:23 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*pt;

	i = 0;
	while (str[i])
		i++;
	pt = malloc((i + 1) * sizeof(char));
	if (!pt)
		return (0);
	i = -1;
	while (str[++i])
		pt[i] = str[i];
	pt[i] = '\0';
	return (pt);
}

int	ft_atoi(const char *str, int *num)
{
	char	*ptr;
	long	nbr;
	int		sign;
	size_t	i;

	ptr = (char *)str;
	nbr = 0;
	sign = 1;
	if (*ptr == '-' && ptr++)
		sign *= -1;
	if (*ptr == '\0')
		return (1);
	i = 0;
	while (*ptr >= '0' && *ptr <= '9' && i++ < 10)
		nbr = nbr * 10 + *ptr++ - '0';
	if (*ptr != '\0' || nbr * sign > 2147483647 || nbr * sign < -2147483648)
		return (1);
	*num = nbr * sign;
	return (0);
}

int	free_prg(t_program *prg)
{
	free_instructions(prg->instr);
	free(prg->stack_a.array);
	free(prg->stack_b.array);
	return (0);
}
