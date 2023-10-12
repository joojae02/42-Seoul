#include "../../libft/libft.h"
#include <stdlib.h>
#include "../../push_swap.h"

int	ft_split_size(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		i++;
	}
	return (i);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}

int	ft_check_atoi(const char *str)
{
	long long	result;
	int			minus;
	int			digit;

	result = 0;
	minus = 1;
	digit = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
		digit++;
	}
	result = result * minus;
	if (*str != '\0' || digit > 10
		|| result > 2147483647 || result < -2147483648)
		print_error(1);
	return ((int)result);
}
