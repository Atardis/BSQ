/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_grid.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 09:43:33 by mdos-san          #+#    #+#             */
/*   Updated: 2015/07/29 10:39:10 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_GRID_H
# define FT_GET_GRID_H
# define BUFFER_SIZE 4096

int		ft_get_length(int *fd, char *file);
char	*ft_allocate_str(int length);
int		ft_assign_str(char **str, int length, int fd);
int		ft_get_info(char **str, int *line, char *ref);
void	ft_get_stdin(int *length);

#endif
