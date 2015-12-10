# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdos-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/07/27 18:58:43 by mdos-san          #+#    #+#              #
#    Updated: 2015/07/30 05:11:18 by mdos-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=bsq

SRC_C=ft_find_square.c ft_error.c ft_get_grid.c main.c
SRC_O=ft_find_square.o ft_error.o ft_get_grid.o main.o
LIB=-L. -lft

FLAGS=-O3 -Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	gcc -c $(SRC_C) $(FLAGS)
	gcc -o $(NAME) $(LIB) $(FLAGS) $(SRC_O)

clean:
	rm -f $(SRC_O)

fclean: clean
	rm -f $(NAME)

re: fclean all
