/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 09:49:07 by adrian            #+#    #+#             */
/*   Updated: 2024/12/21 11:20:43 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	initialize_ray_properties(t_wall *walls, t_scene *scene, int x)
{
	walls->camera_x = 2 * x / (double)WIDTH - 1;
		walls->ray_dir_x = scene->player.dir.x + scene->player.plane.x * walls->camera_x;
		walls->ray_dir_y = scene->player.dir.y + scene->player.plane.y * walls->camera_x;
		if (fabs(walls->ray_dir_x) < 1e-6)
			walls->ray_dir_x = 0;
		if (fabs(walls->ray_dir_y) < 1e-6)
    		walls->ray_dir_y = 0;
		walls->map_x = (int)scene->player.pos.x;
		walls->map_y = (int)scene->player.pos.y;
		if (walls->ray_dir_x == 0)
			walls->delta_dist_x = 1e30;
		else
			walls->delta_dist_x = fabs(1 / walls->ray_dir_x);
		if (walls->ray_dir_y == 0)
			walls->delta_dist_y = 1e30;
		else
			walls->delta_dist_y = fabs(1 / walls->ray_dir_y);
}

void	initialize_step_and_distance(t_wall *walls, t_scene *scene)
{
	if (walls->ray_dir_x < 0)
		{
			walls->step_x = -1;
			walls->side_dist_x = (scene->player.pos.x - walls->map_x) * walls->delta_dist_x;
		}
		else
		{
			walls->step_x = 1;
			walls->side_dist_x = (walls->map_x + 1.0 - scene->player.pos.x) * walls->delta_dist_x;
		}
		if (walls->ray_dir_y < 0)
		{
			walls->step_y = -1;
			walls->side_dist_y = (scene->player.pos.y - walls->map_y) * walls->delta_dist_y;
		}
		else
		{
			walls->step_y = 1;
			walls->side_dist_y = (walls->map_y + 1.0 - scene->player.pos.y) * walls->delta_dist_y;
		}
		walls->hit = 0;
}
//esta funcion realiza el manejo de la iteración para detectar colisiones con las paredes
void	perform_dda(t_wall *walls, t_scene *scene)
{
	while (walls->hit == 0)
	{
		if (walls->side_dist_x < walls->side_dist_y)
		{
			walls->side_dist_x += walls->delta_dist_x;
			walls->map_x += walls->step_x;
			walls->side = 0;
		}
		else
		{
			walls->side_dist_y += walls->delta_dist_y;
			walls->map_y += walls->step_y;
			walls->side = 1;
		}
		if (walls->map_x >= 0 && walls->map_x < scene->cols && walls->map_y >= 0 && walls->map_y < scene->rows)
		{
			if (scene->map[walls->map_y][walls->map_x] == '1')
			{
				walls->hit = 1;
				break ;
			}
		}
	}
}

void	calculate_wall_parameters(t_wall *walls, t_scene *scene)
{
	if (walls->side == 0)
		walls->perp_wall_dist = (walls->map_x - scene->player.pos.x + (1 - walls->step_x) / 2.0) / walls->ray_dir_x;
	else
		walls->perp_wall_dist = (walls->map_y - scene->player.pos.y + (1 - walls->step_y) / 2.0) / walls->ray_dir_y;
	if (walls->perp_wall_dist < 1e-3)
		walls->perp_wall_dist = 1e-3;
	walls->line_height = (int)(HEIGHT / walls->perp_wall_dist);
	walls->draw_start = -walls->line_height / 2 + HEIGHT / 2;
	if (walls->draw_start < 0)
		walls->draw_start = 0;
	walls->draw_end = walls->line_height / 2 + HEIGHT/ 2;
	if (walls->draw_end >= HEIGHT)
		walls->draw_end = HEIGHT - 1;
}

void	draw_walls_loop(t_data *data, t_scene *scene, t_wall *walls, mlx_texture_t *texture)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		initialize_ray_properties(walls, scene, x);
		initialize_step_and_distance(walls, scene);
		perform_dda(walls, scene);
		calculate_wall_parameters(walls, scene);
		texture = select_texture(walls, data);
		walls->step = 1.0 * texture->height / walls->line_height;
		walls->tex_pos = (walls->draw_start - HEIGHT / 2 + walls->line_height / 2) * walls->step;
		y = walls->draw_start;
		while (y < walls->draw_end)
		{
			walls->tex_y = (int)walls->tex_pos & (texture->height - 1);
			walls->tex_pos += walls->step;
			walls->color = ((uint32_t *)texture->pixels)[walls->tex_y * texture->width + walls->tex_x];
			((uint32_t *)data->image->pixels)[y * WIDTH + x] = walls->color;
			y++;
		}
		x++;
	}
}
