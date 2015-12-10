/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_grid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 09:31:37 by mdos-san          #+#    #+#             */
/*   Updated: 2015/07/30 23:07:11 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft.h"
#include "ft_get_grid.h"
#include "ft_error.h"

int		ft_get_length(int *fd, char *file)
{
	int		length;
	int		ret;
	char	*buffer;

	length = 0;
	buffer = (char*)malloc(BUFFER_SIZE);
	if (buffer == 0)
		return (0);
	if (fd == 0)
		while ((ret = read(0, buffer, BUFFER_SIZE)) > 0)
			length = length + ret;
	if (fd != 0)
		while ((ret = read(*fd, buffer, BUFFER_SIZE)) > 0)
			length = length + ret;
	(ret == -1) ? ft_print_error() : 0;
	if (fd > 0)
	{
		(close(*fd) == -1) ? ft_print_error() : 0;
		*fd = open(file, O_RDONLY);
		(*fd == -1) ? ft_print_error() : 0;
	}
	free(buffer);
	return (length);
}

char	*ft_allocate_str(int length)
{
	char *str;

	str = (char*)malloc(sizeof(char) * (length + 1));
	if (str == 0)
		return (0);
	str[length] = '\0';
	return (str);
}

int		ft_assign_str(char **str, int length, int fd)
{
	int		i;
	char	buffer;

	buffer = 0;
	i = 0;
	buffer = 0;
	while (i < length)
	{
		if (read(fd, &buffer, 1) == -1)
			ft_print_error();
		(*str)[i] = buffer;
		i++;
	}
	return (1);
}

int		ft_get_info(char **str, int *line, char *ref)
{
	int	i;
	int	i2;
	int	check;

	i = 0;
	i2 = 3;
	check = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	ref[0] = (*str)[i - 3];
	ref[1] = (*str)[i - 2];
	ref[2] = (*str)[i - 1];
	ref[3] = '\0';
	if (ref[0] == ref[1] || ref[0] == ref[2] || ref[1] == ref[2])
		ft_print_error();
	(*str)[i - 3] = ' ';
	*line = ft_atoi(*str);
	(*str)[i - 3] = ref[0];
	return (1);
}

void	ft_get_stdin(int *length)
{
	char	*buffer;
	char	ref[4];
	int		line;
	int		fd;
	int		ret;

	line = 0;
	buffer = (char*)malloc(BUFFER_SIZE);
	fd = open("menu_maxi_best_of_+.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	(fd == -1) ? ft_print_error() : 0;
	ret = read(0, buffer, BUFFER_SIZE);
	(ret == -1) ? ft_print_error() : write(fd, buffer, ret);
	(*length) = (*length) + ret;
	(close(fd) == -1) ? ft_print_error() : 0;
	fd = open("menu_maxi_best_of_+.txt", O_RDWR | O_APPEND, 0644);
	(fd == -1) ? ft_print_error() : ft_get_info(&buffer, &line, ref);
	while ((ret = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		(ft_char_is_ref(buffer[0], ref) == 0 && buffer[0] != '\n') ?\
		ft_print_error() : write(fd, buffer, ret);
		(*length) = (*length) + ret;
	}
	(ret == -1) ? ft_print_error() : 0;
	free(buffer);
	(close(fd) == -1) ? ft_print_error() : 0;
}
