#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpetrysh <dpetrysh@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/22 15:33:40 by dpetrysh          #+#    #+#              #
#    Updated: 2018/08/22 15:33:41 by dpetrysh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3

SRC_DIR = ./src/
LIB_DIR = ./libft/
MLX_DIR = ./minilibx/

_SRC =  main.c \
		draw_fract.c \
		fractals.c \
		more_fractals.c \
		colors.c \
		events.c \
		additional.c \
		printer.c


SRC = $(_SRC:%.c=$(SRC_DIR)%.c)$
OBJ = $(_SRC:%.c=%.o)$

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L$(LIB_DIR) -lft -g -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

%.o: $(SRC_DIR)%.c 
	$(CC) $(CFLAGS) -I $(LIB_DIR) -c $< -o $@

clean: 
	make -C $(LIB_DIR) clean
	/bin/rm -rf $(OBJ)

fclean: clean
	make -C $(LIB_DIR) fclean
	/bin/rm -rf $(NAME)

re: fclean all
