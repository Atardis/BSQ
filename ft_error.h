/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 18:40:41 by mdos-san          #+#    #+#             */
/*   Updated: 2015/07/29 10:28:19 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

void		ft_print_error(void);
void		ft_check_info(char **str);
int			ft_char_is_ref(char c, char *ref);
void		ft_check_first_line(char *str, char *ref, int *i, int *nb_char);
int			ft_check_grid(char *str, char *ref, int line);

#endif
