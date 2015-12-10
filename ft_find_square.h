/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/29 21:17:56 by mdos-san          #+#    #+#             */
/*   Updated: 2015/07/30 06:50:44 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FIND_SQUARE_H
# define FT_FIND_SQUARE_H

typedef struct		s_var
{
	int	size_sq;
	int	i;
	int	prev_i;
	int	i_of_square;
	int	nb_char;
	int	to_check;
	int	remaining;
	int	line;
}					t_var;

void				ft_resolve(char *str, char *ref, int nb_char, int line);
int					ft_check_square(char *str, char *ref, t_var *var);

#endif
