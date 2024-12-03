// #include "render.h"
// #include "textures.h"
#include "../include/cub3d.h"

void render_walls()
{
    // TODO: Implement rendering of walls using textures
}

void render_floor()
{
    // TODO: Implement rendering of the floor
}

void render_ceiling()
{
    // TODO: Implement rendering of the ceiling
}

void render_scene()
{
    render_walls();
    render_floor();
    render_ceiling();
}

// int	render(void **pack)
// {
// 	t_scene	*scene;
// 	t_keys	*keys;

// 	scene = (t_scene *)(pack[0]);
// 	keys = (t_keys *)(pack[1]);


void render(void *scene_keys)
{
    // t_map *map;

    // t_img   *image;
    // t_mapData map_data;
	// t_scene scene;
	t_data *data = (t_data *)scene_keys;
	// t_keys *key;
	// mlx_image_t image;
	// (void)scene_keys;
	// scene = (t_scene *)(scene_keys[0]);
	// key = (t_keys *)(scene_keys[1]);
    key_hook(data);
    drawBackground(data->image, data->scene);
    //draw_walls(data, data->scene);

    // draw_minimap(scene->mlx, scene->map);
    //draw();

}

void	drawBackground(mlx_image_t *image, t_scene *scene)
{
	int			y;
	int			x;
	// uint32_t	ceiling_color;
	// uint32_t	floor_color;
	// ceiling_color = getColor(map_data->ceiling);
	// floor_color = getColor(map_data->floor);
	// if (ceiling_color == 0 || floor_color == 0)
	// 	return;
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(image, x, y, scene->ccolor);
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx_put_pixel(image, x, y, scene->fcolor);
			x++;
		}
		y++;
	}

	if (mlx_image_to_window(scene->mlx, image, 0, 0) < 0)
	{
		perror("Error al mostrar la imagen en la ventana");
		exit(1);
	}
}

void	draw_walls(t_data *data, t_scene *scene)
{
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			x;
	int			y;
	int			map_x;
	int			map_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	uint32_t	color;

	x = 0;
	while (x < WIDTH)
	{
		if (x == WIDTH / 2)
		{
			camera_x = 0;
			printf("Ray Central [%d]:\n", x);
			printf("  Camera X: %f\n", camera_x);
			printf("  Ray Dir: (%f, %f)\n", ray_dir_x, ray_dir_y);
			// printf("  Player Pos: (%d, %d)\n", data->player_x, map_data->player_y);
			// printf("  Plane: (%f, %f)\n", map_data->plane_x, map_data->plane_y);
		}
		else
			camera_x = 2 * x / (double)WIDTH - 1;
		ray_dir_x = scene->player.dir.x + scene->player.plane.x * camera_x;
		// ray_dir_x = scene->player.player_dir_x + scene->player.plane_x * camera_x;
		// ray_dir_y = scene->player.player_dir_y + scene->player.plane_y * camera_x;
		ray_dir_y = scene->player.dir.y + scene->player.plane.y * camera_x;
		if (fabs(ray_dir_x) < 1e-6)
			ray_dir_x = 0;
		if (fabs(ray_dir_y) < 1e-6)
    		ray_dir_y = 0;
		map_x = (int)scene->player.pos.x;
		map_y = (int)scene->player.pos.y;
		if (ray_dir_x == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = fabs(1 / ray_dir_x);
		if (ray_dir_y == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = fabs(1 / ray_dir_y);
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (scene->player.pos.x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - scene->player.pos.x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (scene->player.pos.y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - scene->player.pos.y) * delta_dist_y;
		}
		hit = 0;
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			if (map_x >= 0 && map_x < WIDTH && map_y >= 0 && map_y < HEIGHT)
			{
				if (scene->map[map_y][map_x] == '1')
					hit = 1;
			}
		}
		if (side == 0)
			perp_wall_dist = (map_x - scene->player.pos.x + (1 - step_x) / 2.0) / ray_dir_x;
		else
			perp_wall_dist = (map_y - scene->player.pos.y + (1 - step_y) / 2.0) / ray_dir_y;
		if (perp_wall_dist < 1e-3)
			perp_wall_dist = 1e-3;
		perp_wall_dist *= 1.5f;
		line_height = (int)(HEIGHT / perp_wall_dist);
		draw_start = -line_height / 2 + HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_height / 2 + HEIGHT/ 2;
		if (draw_end >= HEIGHT)
			draw_end = HEIGHT - 1;
		if (side == 1)
			color = 0xAAAAAA;
		else
			color = 0xFFFFFF;
		y = draw_start;
		while (y < draw_end)
		{
			((uint32_t *)data->image->pixels)[y * WIDTH + x] = color;
			y++;
		}
		x++;
	}
}
