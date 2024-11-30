#ifndef RENDER_H
#define RENDER_H

// Include necessary headers
#include "cub3d.h"

// Function prototypes
void render_scene(t_game *game);
void render_walls(t_game *game);
void render_floor_ceiling(t_game *game);
void render_sprites(t_game *game);
void draw_pixel(t_game *game, int x, int y, int color);
int get_wall_texture_color(t_game *game, int side, double wall_x, double wall_y);
int get_floor_texture_color(t_game *game, double floor_x, double floor_y);
int get_ceiling_texture_color(t_game *game, double ceiling_x, double ceiling_y);

#endif /* RENDER_H */