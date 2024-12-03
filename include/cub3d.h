#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
#include "../42libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"
// # include "raycaster.h"
// # include "input.h"
// # include "render.h"
// # include "textures.h"
// # include "utils.h"

# define WIDTH 900
# define HEIGHT 700

typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct validMap
{
    char    **grid;
    int     height;
    int     width;
    int     ncoins;
    int     nexit;
    char    *north_texture;
    char    *south_texture;
    char    *west_texture;
    char    *east_texture;
    t_color floor;
    t_color ceiling;
    int     x;
    int     y;
}           t_map;

typedef struct s_qtts
{
    int     no;
    int     so;
    int     we;
    int     ea;
    int     f;
    int     c;
    int     y;
    int     door;
    int     is_zero;
}           t_qtt;

typedef struct s_elements
{
    char    *no;
    char    *so;
    char    *we;
    char    *ea;
    char    *f;
    char    *c;
    char    *door;
    t_qtt   qtt;
}           t_elem;

typedef struct s_parser
{
    char **file;
    int rowsfile;
    int rowsy;
    int colsx;
    int letter_player;
    t_elem elem;
}   t_parser;

typedef unsigned int    t_uint;

typedef char            t_byte;

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
}   t_img;

typedef union u_vec2
{
    double  v[2];
    struct
    {
        double  x;
        double  y;
    };
}   t_vec2;

typedef struct s_player
{
    t_vec2  pos;
    t_vec2  dir;
    t_vec2  plane;
    double  dir_len;
    double  v_dist;
    int		player_x;
	int		player_y;
	int		player_dir_x;
	int		player_dir_y;
	double	plane_x;
	double	plane_y;
	char	player_dir;
}   t_player;

typedef struct s_door
{
    int             x;
    int             y;
    char            state;
    double          timer;
    struct s_door   *next;
}   t_door;

typedef struct s_scene
{
    t_player    player;
    t_door      *doors;
    char        **map;
    int         rows;
    int         cols;
    int         prev_frame;
    mlx_t        *mlx;
    void        *win;
    t_img       *screen;
    t_img       *n_wall;
    t_img       *s_wall;
    t_img       *e_wall;
    t_img       *w_wall;
    t_img       *door;
    t_uint      ccolor;
    t_uint      fcolor;
    t_img       *full_map;
    t_img       *mmap;
    t_byte      left_m;
    t_byte      right_m;
    t_vec2      prev_point;
}   t_scene;

// typedef struct s_mapData
// {
// 	t_color	floor;
// 	t_color	ceiling;
// 	t_color	north_texture;
// 	t_color	south_texture;
// 	t_color	west_texture;
// 	t_color	east_texture;
// 	int		player_x;
// 	int		player_y;
// 	int		player_dir_x;
// 	int		player_dir_y;
// 	double	plane_x;
// 	double	plane_y;
// 	char	player_dir;
// 	char	**map;
// 	int		width;
// 	int		height;
// }	t_mapData;


typedef struct s_point
{
    int     x;
    int     y;
}   t_point;

typedef struct s_pos
{
    t_point begin;
}           t_pos;

typedef char	t_byte;

typedef struct s_keys
{
	t_byte	esc;
	t_byte	w;
	t_byte	a;
	t_byte	s;
	t_byte	d;
	t_byte	up;
	t_byte	down;
	t_byte	left;
	t_byte	right;
	t_byte	space;
}	t_keys;

typedef struct  s_cub3d
{
    int         width;
    int         height;
    char        *title;
    // t_player player;
    t_map       map;
    // t_textures   textures;
    // t_color      floor_color;
    // t_color      ceiling_color;
    void        *mlx;
    void        *win;
    // t_image      image;
}               t_cub3d;

typedef struct s_data
{
    char    **map;
    int     width;
    int     height;
    int     colsx;
    int     rowsy;
    mlx_image_t *image;
    // t_mapData *map_data;
    t_scene *scene;
}   t_data;

int check_is_valid(char **check_line);
int check_elem1(char **check_line, t_parser *parser);
int count_args(char **check_line);
t_point	init_pos(void);
int	is_player(char **map, int x, int y);
void    free_parser(t_parser *parser);
void    free_scene(t_parser *parser, t_scene *scene);
int	ft_rowsfile(char **file);
int	check_player(char **map, t_parser *parser);
int	check_space(char **map, int x, int y, char letter_player);
void calc_x_y(t_data *data);
char **padding_map(char **map, int *rows, int *cols);
void    free_data(t_parser *parser, t_data *data, t_scene *scene);
void	delete_enter(char **map);
 void    ft_free_game(char **check_line);
char	*get_next_line(int fd);
 int do_it(t_parser *parser, char *str);
int check_f_c(t_parser *parser, t_scene *scene);
 int check_rgb_nums(char **sp);
 int convert_hexa(char **sp_f, char **sp_c, t_scene *scene);
  char **check_file(char *str);
int count_line(char *str);
 int ft_contains_cub(char *str);
 void parser_init(t_parser *parser, char *str);
int check_elements(t_parser *parser, t_scene *scene);
 int init_map(t_data *data, t_parser *parser);
void set_scene(t_scene *scene, t_parser parser, t_data *data);
 int check_map(t_parser *parser, t_scene scene);
t_player	set_player(char **map);
void key_hook(t_data *data);
void	drawBackground(mlx_image_t *image, t_scene *scene);
void render(void  *scene_keys);
void	draw_walls(t_data *data, t_scene *scene);









int     init_game(t_cub3d *game, char *scene_file);
void    setup_window(t_cub3d *game);
void    render_frame(t_cub3d *game);
void    handle_input(t_cub3d *game);
void    update_player(t_cub3d *game);
void    move_forward(t_cub3d *game);
void    move_backward(t_cub3d *game);
void    strafe_left(t_cub3d *game);
void    strafe_right(t_cub3d *game);
void    rotate_left(t_cub3d *game);
void    rotate_right(t_cub3d *game);
// void    draw_wall(t_cub3d *game, int x, double wall_dist, int wall_height);
void    draw_floor_ceiling(t_cub3d *game, int x, int wall_bottom, int wall_top);
// void draw_sprite(t_cub3d *game, t_sprite *sprite);
void    load_textures(t_cub3d *game);
void    free_textures(t_cub3d *game);
void    parse_scene_file(t_cub3d *game, char *scene_file);
void    parse_resolution(t_cub3d *game, char *line);
// void parse_texture(t_cub3d *game, char *line, t_texture *texture);
// void parse_color(t_cub3d *game, char *line, t_color *color);
void    parse_map(t_cub3d *game, char *line);
void    check_map_validity(t_cub3d *game);
void    exit_error(t_cub3d *game, char *message);

#endif