# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 22:21:03 by aduenas-          #+#    #+#              #
#    Updated: 2024/11/23 12:44:21 by mel-atta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror -I.
LIB = libft.h get_next_line.h
SRC		= 	ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c	\
			ft_memset.c	\
			ft_bzero.c	\
			ft_memcpy.c	\
			ft_memmove.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c	\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_memchr.c	\
			ft_memcmp.c	\
			ft_strnstr.c	\
			ft_atoi.c		\
			ft_calloc.c	\
			ft_strdup.c	\
			ft_strcmp.c \
			ft_substr.c	\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c	\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			get_next_line.c \
			get_next_line_utils.c

OBJ	= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	ar rcs $(NAME) $(OBJ)

%.o: %.c $(LIB)
	cc $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
