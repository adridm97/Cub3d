/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:28:30 by adrian            #+#    #+#             */
/*   Updated: 2024/12/13 16:25:25 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void init_textures(t_data *data)
{
	data->scene->textures = malloc(sizeof(mlx_texture_t *) * 4);
	printf("Ruta de carga: %s\n", data->parser->elem.no);
	if (ft_strcmp(data->parser->elem.no, "assets/north.png") == 0) 
	{
		data->scene->textures[0] = mlx_load_png(data->parser->elem.no);
		if (!data->scene->textures[0])
			printf("Error al cargar textura norte: %s\n", data->parser->elem.no);
	}
	else
		printf("Error: Ruta de textura norte es NULL\n");

	if (data->parser->elem.so)
	{
		data->scene->textures[1] = mlx_load_png("assets/south.png");
		if (!data->scene->textures[1])
			printf("Error al cargar textura sur: %s\n", data->parser->elem.so);
	}
	else
		printf("Error: Ruta de textura sur es NULL\n");

	if (data->parser->elem.ea)
	{
		data->scene->textures[2] = mlx_load_png("assets/east.png");
		if (!data->scene->textures[2])
			printf("Error al cargar textura este: %s\n", data->parser->elem.ea);
	}
	else
		printf("Error: Ruta de textura este es NULL\n");

	if (data->parser->elem.we)
	{
		data->scene->textures[3] = mlx_load_png("assets/west.png");
		if (!data->scene->textures[3])
			printf("Error al cargar textura oeste: %s\n", data->parser->elem.we);
	}
	else
		printf("Error: Ruta de textura oeste es NULL\n");
}


void render(void *scene_keys)
{
	t_data *data;

	data = (t_data *)scene_keys;
	if (!data || !data->scene || !data->image)
	{
		perror("Error: Datos de escena no inicializados correctamente.\n");
		return ;
	}
	init_textures(data);
	init_minimap(data);
    key_hook(data);
    drawBackground(data->image, data->scene);
    draw_walls(data, data->scene);
    draw_minimap(data);
}

void	drawBackground(mlx_image_t *image, t_scene *scene)
{
	int	y;
	int	x;

	if (scene->ccolor == 0 || scene->fcolor == 0)
    {
        printf("Error: Los colores del fondo no son válidos (ccolor: %x, fcolor: %x).\n", scene->ccolor, scene->fcolor);
        return;
    }
    if (!image)
    {
        printf("Error: La imagen no está inicializada.\n");
        return;
    }
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
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				x;
	int				y;
	int				map_x;
	int				map_y;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	double			wall_x;
	uint32_t		color;
	mlx_texture_t	*texture;

	texture = NULL;
	x = 0;
	if (!scene || !scene->map || !data->image)
	{
		printf("Error: Datos de escena no válidos en draw_walls.\n");
		return;
	}
	while (x < WIDTH)
	{
		if (x == WIDTH / 2)
		{
			camera_x = 0;
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
			if (map_x >= 0 && map_x < scene->cols && map_y >= 0 && map_y < scene->rows)
			{
				if (scene->map[map_y][map_x] == '1')
				{
					hit = 1;
					break;
				}
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
		// if (side == 0)
        // {
        //     if (ray_dir_x > 0)
		// 	{
        //         color = 0xFF0000FF;
		// 	}
        //     else
		// 	{
        //         color = 0xFFFF0000;
		// 	}
        // }
        // else
        // {
        //     if (ray_dir_y > 0)
		// 	{
        //         color = 0xFF00FF00;
		// 	}
        //     else
		// 	{
        //         color = 0xFFFF00FF;
		// 	}
        // }
		if (side == 0)
		{
			if (ray_dir_x > 0)
				texture = data->scene->textures[0];
			else
				texture = data->scene->textures[1];
		}
		else
		{
			if (ray_dir_y > 0)
				texture = data->scene->textures[2];
			else
				texture = data->scene->textures[3];
		}

		if (side == 0)
		wall_x = scene->player.pos.y + perp_wall_dist * ray_dir_y;
		else
		wall_x = scene->player.pos.x + perp_wall_dist * ray_dir_x;
		wall_x -= floor(wall_x);
		tex_x = (int)(wall_x * texture->width);
		if ((side == 0 && ray_dir_x < 0) || (side == 1 && ray_dir_y > 0))
			tex_x = texture->width - tex_x - 1;
		step = 1.0 * texture->height / line_height;
		tex_pos = (draw_start - HEIGHT / 2 + line_height / 2) * step;
		y = draw_start;
		while (y < draw_end)
		{
			tex_y = (int)tex_pos & (texture->height - 1);
			tex_pos += step;
			color = ((uint32_t *)texture->pixels)[tex_y * texture->width + tex_x];
			((uint32_t *)data->image->pixels)[y * WIDTH + x] = color;
			y++;
		}
		x++;
	}
}
