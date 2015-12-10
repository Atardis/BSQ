/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/28 11:28:15 by mdos-san          #+#    #+#             */
/*   Updated: 2015/07/29 13:06:49 by mdos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_putchar(char c);
void	ft_putstr(char *c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
char	**ft_split_whitespaces(char *str);
int		ft_is_digit(char c);
char	*ft_strcat(char *dest, char *src);

#endif
