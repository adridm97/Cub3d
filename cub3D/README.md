# cub3D

This is a simple RayCaster game implemented in C using the miniLibX library. The game renders a 3D maze and allows the player to navigate through it.

## Project Structure

```
cub3D
├── src
│   ├── main.c
│   ├── raycaster.c
│   ├── input.c
│   ├── render.c
│   ├── textures.c
│   ├── utils.c
│   └── map_parser.c
├── include
│   ├── cub3d.h
│   ├── raycaster.h
│   ├── input.h
│   ├── render.h
│   ├── textures.h
│   └── utils.h
├── assets
│   ├── north_texture.xpm
│   ├── south_texture.xpm
│   ├── west_texture.xpm
│   ├── east_texture.xpm
│   └── sample_map.cub
├── lib
│   └── libft
│       ├── Makefile
│       ├── libft.h
│       └── ...
├── Makefile
└── README.md
```

## Files

- `src/main.c`: Entry point of the program. Initializes the miniLibX, sets up the window, and starts the game loop.
- `src/raycaster.c`: Implementation of the raycasting algorithm. Calculates the distance to walls and renders the 3D view of the maze.
- `src/input.c`: Handles user input. Listens for keyboard events and updates the player's position and orientation accordingly.
- `src/render.c`: Responsible for rendering the graphics. Uses the textures and colors specified in the scene description file to draw the walls, floor, and ceiling.
- `src/textures.c`: Loads and manages the wall textures. Reads the texture files specified in the scene description file and stores them in memory.
- `src/utils.c`: Contains utility functions used throughout the program, such as parsing numbers and error handling.
- `src/map_parser.c`: Parses the scene description file (.cub) and extracts the necessary information, such as the map layout, textures, and colors.
- `include/cub3d.h`: Function prototypes and data structures used in the main program.
- `include/raycaster.h`: Function prototypes and data structures related to the raycasting algorithm.
- `include/input.h`: Function prototypes and data structures related to user input handling.
- `include/render.h`: Function prototypes and data structures related to rendering graphics.
- `include/textures.h`: Function prototypes and data structures related to loading and managing textures.
- `include/utils.h`: Function prototypes and data structures for utility functions.
- `assets/north_texture.xpm`: Example of a wall texture for the north side of the walls.
- `assets/south_texture.xpm`: Example of a wall texture for the south side of the walls.
- `assets/west_texture.xpm`: Example of a wall texture for the west side of the walls.
- `assets/east_texture.xpm`: Example of a wall texture for the east side of the walls.
- `assets/sample_map.cub`: Example of a scene description file (.cub) that specifies the map layout, textures, and colors.
- `lib/libft/Makefile`: Makefile used to compile the libft library.
- `lib/libft/libft.h`: Function prototypes and data structures for the libft library.
- `Makefile`: Makefile used to compile the cub3D program. Includes necessary flags and dependencies.
- `README.md`: Documentation for the project. Provides an overview of the project and instructions on how to build and run it.

## Building and Running

To build the cub3D program, run the following command:

```
make
```

To run the program, use the following command:

```
./cub3D path_to_scene_file.cub
```

Replace `path_to_scene_file.cub` with the path to your own scene description file.

## Controls

- Use the left and right arrow keys to look left and right in the maze.
- Use the W, A, S, and D keys to move the point of view through the maze.
- Press ESC or click on the red cross on the window's frame to close the window and quit the program.

Enjoy playing cub3D!