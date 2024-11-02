CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = cub
SRCS = main.c parse.c minmap.c key_events.c #parse_player.c
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
	cd MLX42/build && make clean
fclean: clean
	rm -f $(NAME)
	make -C 42libft fclean
	rm -rf MLX42/build
re: fclean all
.PHONY: all clean fclean re