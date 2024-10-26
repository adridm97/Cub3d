#ifndef UTILS_H
#define UTILS_H

// Function prototypes for utility functions

// Function to parse the scene description file
int parse_scene_file(const char* filename);

// Function to check if a character is a valid map element
int is_valid_map_element(char c);

// Function to check if a map is valid (closed/surrounded by walls)
int is_valid_map(char** map, int width, int height);

// Function to free the memory allocated for the map
void free_map(char** map, int height);

#endif /* UTILS_H */