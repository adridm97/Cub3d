# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrian <adrian@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 21:44:47 by aduenas-          #+#    #+#              #
#    Updated: 2024/12/25 00:31:32 by adrian           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3 -fsanitize=address
NAME = cub3D
HEADER = include/cub3d.h
LIBFT = 42libft/libft.a
SRCS = cub3D.c src/check_map.c src/check_player.c src/ft_free.c src/map_parser.c \
	src/set_scene.c src/utils.c src/utils2.c src/set_player.c src/render.c src/key_events.c src/minmap.c \
	src/free.c src/handle_mouse_move.c src/player_colision.c src/errors.c src/textures.c src/walls.c \
	src/exit.c src/vectors.c src/trim.c src/utils3.c
OBJS = $(SRCS:.c=.o)
MLX_LIB_DIR = MLX42/build
MLX_LIB = -L$(MLX_LIB_DIR) -lmlx42
%.o: %.c $(LIBFT) Makefile $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
all: libft $(NAME) Makefile
$(MLX_LIB_DIR)/libmlx42.a:
	cd MLX42 && cmake -B build
	cd MLX42/build && make
$(NAME): $(LIBFT) $(OBJS) $(MLX_LIB_DIR)/libmlx42.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) -Iinclude -ldl -lglfw -pthread -lm $(LIBFT)
libft:
	${MAKE} -C ./42libft
clean:
	rm -f $(OBJS)
	make -C 42libft clean
	cd MLX42 && cmake -B build
	cd MLX42/build && make clean
fclean: clean
	rm -f $(NAME)
	make -C 42libft fclean
	rm -rf MLX42/build
re: fclean all
.PHONY: libft all clean fclean re