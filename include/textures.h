#ifndef TEXTURES_H
#define TEXTURES_H

// Include necessary headers here

// Define the structure for storing textures
typedef struct {
    // Define the properties of the textures here
} Textures;

// Declare function prototypes for loading and managing textures
void load_textures(Textures* textures, const char* path_to_north_texture, const char* path_to_south_texture, const char* path_to_west_texture, const char* path_to_east_texture);
void free_textures(Textures* textures);

#endif /* TEXTURES_H */