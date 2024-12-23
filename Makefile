CC = cc
CFLAGS = -Wall -Wextra -Werror -g -O3 -fsanitize=address
NAME = cub
SRCS = cub3D.c src/check_map.c src/check_player.c src/ft_free.c src/map_parser.c \
	src/set_scene.c src/utils.c src/utils2.c src/set_player.c src/render.c src/key_events.c src/minmap.c \
	src/free.c src/handle_mouse_move.c src/player_colision.c src/errors.c src/textures.c src/walls.c \
	src/exit.c src/vectors.c src/trim.c
#parse.c minmap.c key_events.c parse_player.c ray_casting.c
OBJS = $(SRCS:.c=.o)
LIBFT = 42libft/libft.a
MLX_LIB_DIR = MLX42/build
MLX_LIB = -L$(MLX_LIB_DIR) -lmlx42

all: $(NAME)
$(MLX_LIB_DIR)/libmlx42.a:
	cd MLX42 && cmake -B build
	cd MLX42/build && make
$(NAME): $(LIBFT) $(OBJS) $(MLX_LIB_DIR)/libmlx42.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_LIB) -Iinclude -ldl -lglfw -pthread -lm $(LIBFT)
$(LIBFT):
	make -C 42libft
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
.PHONY: all clean fclean re