/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 18:40:34 by mdos-san          #+#    #+#             */
/*   Updated: 2015/07/30 22:35:18 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft.h"
#include "ft_error.h"

void	ft_print_error(void)
{
	write(2, "map error\n", 10);
	exit(0);
}

void	ft_check_info(char **str)
{
	int	i;
	int	nb_digit;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != 0)
		i++;
	nb_digit = i - 3;
	if (nb_digit <= 0)
		ft_print_error();
	i = 0;
	while (i < nb_digit)
	{
		if (ft_is_digit((*str)[i]) == 0)
			ft_print_error();
		i++;
	}
}

int		ft_char_is_ref(char c, char *ref)
{
	if (c != ref[0] && c != ref[1])
		return (0);
	return (1);
}

void	ft_check_first_line(char *str, char *ref, int *i, int *nb_char)
{
	while (str[*i] != '\n' && str[*i] != '\0')
		(*i)++;
	(str[*i] == 0) ? ft_print_error() : (*i)++;
	while (str[*i] != '\n' && str[*i] != '\0')
	{
		(ft_char_is_ref(str[*i], ref) == 0) ? ft_print_error() : (*nb_char)++;
		(*i)++;
	}
	(str[*i] == 0) ? ft_print_error() : (*i)++;
	(*nb_char == 0) ? ft_print_error() : 0;
}

int		ft_check_grid(char *str, char *ref, int line)
{
	int	i;
	int	nb_char;
	int	count;
	int	nb_line;

	i = 0;
	nb_char = 0;
	nb_line = 0;
	count = 0;
	ft_check_first_line(str, ref, &i, &nb_char);
	nb_line++;
	while (str[i] != 0)
	{
		if (str[i] == '\n')
		{
			nb_line++;
			(count != nb_char) ? ft_print_error() : (count = 0);
			i++;
			if (str[i] == 0)
				break ;
		}
		(ft_char_is_ref(str[i], ref) == 0) ? ft_print_error() : i++, count++;
	}
	(line != nb_line) ? ft_print_error() : 0;
	return (nb_char);
}
