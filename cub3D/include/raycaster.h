#ifndef RAYCASTER_H
#define RAYCASTER_H

// Include necessary headers
#include "cub3d.h"

// Function prototypes
void raycast(MapData* mapData, Player* player, Image* image);
void render_walls(MapData* mapData, Player* player, Image* image);
void render_floor_ceiling(MapData* mapData, Player* player, Image* image);
void render_sprites(MapData* mapData, Player* player, Image* image);
void update_player(Player* player, InputState* inputState, MapData* mapData);
void handle_input(InputState* inputState);
void draw_image(Image* image);
void clear_image(Image* image);
void destroy_image(Image* image);

#endif /* RAYCASTER_H */