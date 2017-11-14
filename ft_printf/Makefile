#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tde-roqu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/12 14:38:34 by tde-roqu          #+#    #+#              #
#    Updated: 2016/01/28 15:41:19 by tde-roqu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ft_itoabase.c ft_mintomaj.c ft_printf.c ft_str.c ft_strsub.c \
ft_itoabasellu.c ft_modif.c ft_strcat.c ft_unsignednbr.c ft_itoabaselu.c \
ft_nbr.c ft_putchar.c ft_strcpy.c ft_width.c ft_itoabaseumax.c ft_newstruc.c \
ft_putnbr.c ft_strdup.c ft_xonbr.c ft_atoi.c ft_itoalong.c ft_optone.c \
ft_putstr.c ft_strlen.c ft_flag.c ft_itoalonglong.c ft_othernbr.c \
ft_strncpy.c ft_itoa.c ft_itoamax.c ft_precision.c ft_strnew.c ft_btoi.c \
ft_putwchar.c ft_putwstr.c ft_itoabaseshort.c ft_specwidth.c ft_error.c \
ft_specprecision.c ft_xonbrhh.c ft_strdel.c ft_memdel.c

OBJ = $(SRC:.c=.o)

FLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
