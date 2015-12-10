/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 13:55:25 by mdos-san          #+#    #+#             */
/*   Updated: 2015/07/30 06:53:08 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"
#include "ft_find_square.h"
#include "ft_error.h"

void	ft_display_result(char *str, char *ref, t_var var)
{
	int		count;
	int		x;
	int		y;

	count = 0;
	x = 0;
	y = 0;
	while (y < var.size_sq)
	{
		while (x < var.size_sq)
		{
			str[var.i_of_square + x] = ref[2];
			x++;
		}
		var.i_of_square = var.i_of_square + var.nb_char + 1;
		x = 0;
		y++;
	}
	while (str[count] != '\n')
		count++;
	count++;
	str = str + count;
	write(1, str, var.line * (var.nb_char + 1));
}

int		ft_check_square(char *str, char *ref, t_var *var)
{
	int	count;

	count = 0;
	if (var->to_check == 0)
	{
		var->i_of_square = var->prev_i;
		var->i = var->prev_i;
		var->size_sq++;
		var->to_check = var->size_sq;
		return (1);
	}
	while (count < var->size_sq)
	{
		if (str[var->i + count] == ref[1] || str[var->i + count] == '\n')
		{
			(str[var->i + count] == '\n') ? var->remaining-- : 0;
			var->i = var->prev_i + count + 1;
			var->to_check = var->size_sq;
			return (0);
		}
		count++;
	}
	var->i = var->i + var->nb_char + 1;
	var->to_check--;
	return (ft_check_square(str, ref, var));
}

void	ft_resolve(char *str, char *ref, int nb_char, int line)
{
	t_var var;

	var.i = 0;
	var.prev_i = 0;
	var.size_sq = 1;
	var.to_check = 1;
	var.nb_char = nb_char;
	var.i_of_square = 0;
	var.remaining = line;
	var.line = line;
	while (str[var.i] != '\n' && str[var.i] != 0)
		var.i++;
	if (str[var.i] == 0)
		ft_print_error();
	var.i++;
	while (str[var.i] != 0)
	{
		var.prev_i = var.i;
		if (var.remaining < var.size_sq)
			break ;
		ft_check_square(str, ref, &var);
	}
	var.size_sq--;
	ft_display_result(str, ref, var);
}
