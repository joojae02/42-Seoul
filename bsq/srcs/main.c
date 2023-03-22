/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 01:20:55 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/28 01:20:56 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	main(int argc, char *argv[])
{
	int		fd;
	int		i;
	t_bsq	f_b;

	i = 1;
	if (argc == 1)
		read_file(0, &f_b);
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			read_file(fd, &f_b);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
}

void	read_file(int fd, t_bsq *f_b)
{
	char	**map;
	char	*buff;
	char	*result;

	buff = 0;
	result = 0;
	if (fd >= 0)
	{
		map = read_map(fd, f_b, buff, result);
		if (map == 0)
			write(1, "map error\n", 10);
		else
		{
			if (fd == 0)
				write(1, "\n", 1);
			ft_convert(f_b, map);
			ft_free(f_b, map, buff, result);
		}
	}
	else
		write(1, "map error\n", 10);
}

char	**read_map(int fd, t_bsq *f_b, char *buff, char *result)
{
	ssize_t	size;
	int		index;

	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	result = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	*result = '\0';
	index = 1;
	size = read(fd, buff, BUFF_SIZE);
	while (size > 0)
	{
		buff[size + 1] = '\0';
		if (size == BUFF_SIZE)
			result = ft_realloc(result, (index * BUFF_SIZE) + 1);
		ft_strcat(result, buff);
		index++;
		size = read(fd, buff, BUFF_SIZE);
	}
	free(buff);
	ft_init_t_bsq(result, f_b);
	if (ft_check_all(f_b, result))
		return (0);
	return (make_map(result, f_b));
}

void	ft_init_t_bsq(char *buff, t_bsq *f_b)
{
	int		first_line_size;
	char	*first_line;
	int		i;
	int		col_size;

	first_line_size = 0;
	while (buff[first_line_size] != '\n')
		first_line_size++;
	first_line = (char *)malloc(sizeof(char) * (first_line_size + 1));
	first_line[first_line_size] = '\0';
	i = -1;
	while (buff[++i] != '\n')
		first_line[i] = buff[i];
	col_size = 0;
	while (buff[++i] != '\n')
		col_size++;
	f_b -> empty = first_line[first_line_size - 3];
	f_b -> obstacle = first_line[first_line_size - 2];
	f_b -> full = first_line[first_line_size - 1];
	first_line[first_line_size - 3] = '\0';
	f_b -> row = ft_atoi(first_line);
	f_b -> col = col_size;
}

char	**make_map(char *buff, t_bsq *f_b)
{
	int		i;
	int		j;
	int		start;
	char	**map;
	int		check;

	i = 0;
	while (buff[i++] != '\n')
	check = 0;
	map = (char **)malloc(sizeof(char *) * (f_b -> row + 1));
	start = -1;
	while (++start < f_b -> row)
		map[start] = (char *)malloc(sizeof(char) * (f_b -> col + 1));
	start = -1;
	while (++start < f_b -> row)
	{
		j = -1;
		while (++j < f_b -> col)
			map[start][j] = buff[i + j];
		map[start][j] = '\0';
		i += j + 1;
	}
	map[start] = 0;
	free(buff);
	return (map);
}
