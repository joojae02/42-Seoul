/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyjoo <jaehyjoo@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:43:34 by jaehyjoo          #+#    #+#             */
/*   Updated: 2023/02/27 13:02:31 by jaehyjoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char *argv[])
{
	if (argc == 1)
		write(1, "File name missing.\n", 19);
	else if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}

}

void	display_file(char *file_name)
{
	int	file;

	file = open(file_name, O_RDONLY);
	if (file == -1)
	{
		write(1, "Cannot read file.\n", 18);
		return ;
	}
	
	
}
