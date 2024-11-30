/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:29:45 by adrian            #+#    #+#             */
/*   Updated: 2024/11/30 14:20:26 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

// void	draw_walls(mlx_image_t *image, t_mapData *map_data)
// {
// 	int			step_x;
// 	int			step_y;
// 	int			hit;
// 	int			side;
// 	int			x;
// 	int			y;
// 	int			map_x;
// 	int			map_y;
// 	int			line_height;
// 	int			draw_start;
// 	int			draw_end;
// 	double		camera_x;
// 	double		ray_dir_x;
// 	double		ray_dir_y;
// 	double		side_dist_x;
// 	double		side_dist_y;
// 	double		delta_dist_x;
// 	double		delta_dist_y;
// 	double		perp_wall_dist;
// 	uint32_t	color;

// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		if (x == WIDTH / 2)
// 		{
// 			camera_x = 0;
// 			printf("Ray Central [%d]:\n", x);
// 			printf("  Camera X: %f\n", camera_x);
// 			printf("  Ray Dir: (%f, %f)\n", ray_dir_x, ray_dir_y);
// 			printf("  Player Pos: (%d, %d)\n", map_data->player_x, map_data->player_y);
// 			printf("  Plane: (%f, %f)\n", map_data->plane_x, map_data->plane_y);
// 		}
// 		else
// 			camera_x = 2 * x / (double)WIDTH - 1;
// 		ray_dir_x = map_data->player_dir_x + map_data->plane_x * camera_x;
// 		ray_dir_y = map_data->player_dir_y + map_data->plane_y * camera_x;
// 		if (fabs(ray_dir_x) < 1e-6)
// 			ray_dir_x = 0;
// 		if (fabs(ray_dir_y) < 1e-6)
//     		ray_dir_y = 0;
// 		map_x = (int)map_data->player_x;
// 		map_y = (int)map_data->player_y;
// 		if (ray_dir_x == 0)
// 			delta_dist_x = 1e30;
// 		else
// 			delta_dist_x = fabs(1 / ray_dir_x);
// 		if (ray_dir_y == 0)
// 			delta_dist_y = 1e30;
// 		else
// 			delta_dist_y = fabs(1 / ray_dir_y);
// 		if (ray_dir_x < 0)
// 		{
// 			step_x = -1;
// 			side_dist_x = (map_data->player_x - map_x) * delta_dist_x;
// 		}
// 		else
// 		{
// 			step_x = 1;
// 			side_dist_x = (map_x + 1.0 - map_data->player_x) * delta_dist_x;
// 		}
// 		if (ray_dir_y < 0)
// 		{
// 			step_y = -1;
// 			side_dist_y = (map_data->player_y - map_y) * delta_dist_y;
// 		}
// 		else
// 		{
// 			step_y = 1;
// 			side_dist_y = (map_y + 1.0 - map_data->player_y) * delta_dist_y;
// 		}
// 		hit = 0;
// 		while (hit == 0)
// 		{
// 			if (side_dist_x < side_dist_y)
// 			{
// 				side_dist_x += delta_dist_x;
// 				map_x += step_x;
// 				side = 0;
// 			}
// 			else
// 			{
// 				side_dist_y += delta_dist_y;
// 				map_y += step_y;
// 				side = 1;
// 			}
// 			if (map_x >= 0 && map_x < map_data->width && map_y >= 0 && map_y < map_data->height)
// 			{
// 				if (map_data->map[map_y][map_x] == '1')
// 					hit = 1;
// 			}
// 		}
// 		if (side == 0)
// 			perp_wall_dist = (map_x - map_data->player_x + (1 - step_x) / 2.0) / ray_dir_x;
// 		else
// 			perp_wall_dist = (map_y - map_data->player_y + (1 - step_y) / 2.0) / ray_dir_y;
// 		if (perp_wall_dist < 1e-3)
// 			perp_wall_dist = 1e-3;
// 		perp_wall_dist *= SCALE;
// 		line_height = (int)(HEIGHT / perp_wall_dist);
// 		draw_start = -line_height / 2 + HEIGHT / 2;
// 		if (draw_start < 0)
// 			draw_start = 0;
// 		draw_end = line_height / 2 + HEIGHT / 2;
// 		if (draw_end >= HEIGHT)
// 			draw_end = HEIGHT - 1;
// 		if (side == 1)
// 			color = 0xAAAAAA;
// 		else
// 			color = 0xFFFFFF;
// 		y = draw_start;
// 		while (y < draw_end)
// 		{
// 			((uint32_t *)image->pixels)[y * WIDTH + x] = color;
// 			y++;
// 		}
// 		x++;
// 	}
// }
