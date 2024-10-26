#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
// # include "raycaster.h"
// # include "input.h"
// # include "render.h"
// # include "textures.h"
// # include "utils.h"

typedef struct validMap
{
	char	**grid;
	int		height;
	int		width;
	int		ncoins;
	int		nexit;
	int		x;
	int		y;
}			t_map;

typedef struct	s_cub3d
{
	int			width;
	int			height;
	char		*title;
	// t_player	player;
	t_map		map;
	// t_textures	textures;
	// t_color		floor_color;
	// t_color		ceiling_color;
	void		*mlx;
	void		*win;
	// t_image		image;
}				t_cub3d;

int		init_game(t_cub3d *game, char *scene_file);
void	setup_window(t_cub3d *game);
void	render_frame(t_cub3d *game);
void	handle_input(t_cub3d *game);
void	update_player(t_cub3d *game);
void	move_forward(t_cub3d *game);
void	move_backward(t_cub3d *game);
void	strafe_left(t_cub3d *game);
void	strafe_right(t_cub3d *game);
void	rotate_left(t_cub3d *game);
void	rotate_right(t_cub3d *game);
void	draw_wall(t_cub3d *game, int x, double wall_dist, int wall_height);
void	draw_floor_ceiling(t_cub3d *game, int x, int wall_bottom, int wall_top);
// void	draw_sprite(t_cub3d *game, t_sprite *sprite);
void	load_textures(t_cub3d *game);
void	free_textures(t_cub3d *game);
void	parse_scene_file(t_cub3d *game, char *scene_file);
void	parse_resolution(t_cub3d *game, char *line);
// void	parse_texture(t_cub3d *game, char *line, t_texture *texture);
// void	parse_color(t_cub3d *game, char *line, t_color *color);
void	parse_map(t_cub3d *game, char *line);
void	check_map_validity(t_cub3d *game);
void	exit_error(t_cub3d *game, char *message);

#endif