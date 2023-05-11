/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:44:02 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/03/01 10:44:04 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# define BUFF_SIZE 1024

typedef struct ft_bsq
{
	int		row;
	int		col;
	char	empty;
	char	obstacle;
	char	full;
}	t_bsq;

int		ft_atoi(char *str);
void	*ft_realloc(void *ptr, unsigned int size);
char	**read_map(int fd, t_bsq *f_b, char *buff, char *result);
void	ft_init_t_bsq(char *buff, t_bsq *f_b);
int		ft_strlen(char *src);
char	**make_map(char *buff, t_bsq *f_b);
char	*ft_strcat(char *dest, char *src);
int		ft_check_all(t_bsq *f_b, char *buff);
void	ft_free(t_bsq *f_b, char **map, char *buff, char *result);
void	ft_print_map(char **map, t_bsq *f_b);
void	ft_convert(t_bsq *f_b, char **map);
void	read_file(int fd, t_bsq *f_b);
void	ft_solve(t_bsq *f_b, int **int_map, char **map, int max);

#endif
