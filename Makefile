#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/16 11:33:12 by tde-roqu          #+#    #+#              #
#    Updated: 2016/03/25 13:48:22 by tde-roqu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = main.c ft_hooks.c ft_init.c ft_drawseg.c ft_file_collect.c ft_lstft.c\
get_next_line.c ft_proj_ortho.c ft_centring.c

OBJ = $(SRC:.c=.o)

HEAD = ft_printf/

FLAGS = -Wall -Wextra -Werror

FLAGSEND = -lmlx -framework OpenGL\
-framework AppKit

all: $(NAME)

$(NAME):
	make -C ft_printf/ fclean && make -C ft_printf/
	gcc $(FLAGS) -I $(HEAD) -c $(SRC)
	gcc -o $(NAME) $(OBJ) -I $(HEAD) -L ft_printf/ -lftprintf $(FLAGSEND)

clean:
	make -C ft_printf/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C ft_printf/ fclean
	rm -f $(NAME)

re: fclean all