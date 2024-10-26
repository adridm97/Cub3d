CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = cub3D
SRCS =
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a


all: $(NAME)
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)
$(LIBFT):
	make -C libft
clean:
	rm -f $(OBJS)
	make -C libft clean
fclean: clean
	rm -f $(NAME)
	make -C libft fclean
re: fclean all