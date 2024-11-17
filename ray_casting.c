/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 10:29:45 by adrian            #+#    #+#             */
/*   Updated: 2024/11/11 11:49:47 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	draw_walls(void *mlx, t_mapData *map_data)
{
	int		step_x;
    int		step_y;
	int		hit;
	int		side;
	int		x;
	int		map_x;
	int		map_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;

	hit = 0;
	x = 0;
	camera_x = 2 * x / (double)WIDTH - 1;
	ray_dir_x = map_data->player_dir_x + map_data->plane_x * camera_x;
	ray_dir_y = map_data->player_dir_y + map_data->plane_y * camera_x;
	map_x = (int)map_data->player_x;
	map_y = (int)map_data->player_y;
	delta_dist_x = fabs(1 / ray_dir_x);
	delta_dist_y = fabs(1 / ray_dir_y);
	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (map_data->player_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - map_data->player_x) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (map_data->player_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - map_data->player_y) * delta_dist_y;
    }
	
}
