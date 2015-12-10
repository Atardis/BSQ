/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/27 19:49:24 by mdos-san          #+#    #+#             */
/*   Updated: 2015/07/30 08:44:05 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft.h"
#include "ft_get_grid.h"
#include "ft_error.h"
#include "ft_find_square.h"

void	ft_read_stdin(int fd)
{
	int		length;
	int		line;
	int		nb_char;
	char	*str;
	char	ref[4];

	line = 0;
	nb_char = 0;
	length = 0;
	ft_get_stdin(&length);
	fd = open("menu_maxi_best_of_+.txt", O_RDONLY);
	str = ft_allocate_str(length);
	ft_assign_str(&str, length, fd);
	close(fd);
	ft_check_info(&str);
	ft_get_info(&str, &line, ref);
	nb_char = ft_check_grid(str, ref, line);
	ft_resolve(str, ref, nb_char, line);
	free(str);
}

void	ft_read_params(char **av, int i, int fd)
{
	int		length;
	int		line;
	int		nb_char;
	char	*str;
	char	ref[4];

	line = 0;
	nb_char = 0;
	fd = open(av[i - 1], O_RDONLY);
	length = ft_get_length(&fd, av[i - 1]);
	str = ft_allocate_str(length);
	ft_assign_str(&str, length, fd);
	close(fd);
	ft_check_info(&str);
	ft_get_info(&str, &line, ref);
	nb_char = ft_check_grid(str, ref, line);
	ft_resolve(str, ref, nb_char, line);
	free(str);
}

int		main(int ac, char **av)
{
	int		i;
	int		fd;

	i = 2;
	fd = 0;
	if (ac == 1)
		ft_read_stdin(fd);
	while (i <= ac)
	{
		ft_read_params(av, i, fd);
		i++;
	}
	return (0);
}
