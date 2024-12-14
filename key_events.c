/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:57:16 by adrian            #+#    #+#             */
/*   Updated: 2024/12/09 11:55:37 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "functions.h"
#include "include/cub3d.h"

bool	is_wall(t_data *data, float x, float y)
{
	int	map_x;
	int	map_y;
	int	padding;

	map_y = (int)(y / data->minimap.scale_y);
	map_x = (int)(x / data->minimap.scale_x);
	if (map_x < 0 || map_x >= data->colsx || map_y < 0 || map_y >= data->rowsy)
		return true;
	if (data->scene->map[map_y][map_x] == '1')
		return true;
	padding = 1;
	if ((map_x + padding) < data->colsx && data->scene->map[map_y][map_x + padding] == '1')
		return true;
	if ((map_x - padding) >= 0 && data->scene->map[map_y][map_x - padding] == '1')
		return true;
	if ((map_y - padding) >= 0 && data->scene->map[map_y - padding][map_x] == '1')
		return true;
	if ((map_y + padding) < data->rowsy && data->scene->map[map_y + padding][map_x] == '1')
		return true;
	return false;
}



t_vec2	sum_vec2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return (v);
}

t_vec2	rotate_vec2(t_vec2 vec, double angle)
{
	t_vec2	rotated;

	rotated.x = vec.x * cos(angle) - vec.y * sin(angle);
	rotated.y = vec.x * sin(angle) + vec.y * cos(angle);
	return (rotated);
}

void	key_hook(t_data *data)
{
	t_vec2	move;
	double	rotation_speed;
	double	move_speed;
	float	new_x;
	float	new_y;

	move_speed = 0.1;
	rotation_speed = 0.1;
	ft_memset(&move, 0, sizeof(t_vec2));
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_ESCAPE))
	{
		exit(0);
	}
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_W))
	{
		new_x = data->scene->player.pos.x + data->scene->player.dir.x * move_speed;
		new_y = data->scene->player.pos.y + data->scene->player.dir.y * move_speed;
		printf("Intento mover a (%f, %f)\n", new_x, new_y);
		if (!is_wall(data, new_x, new_y))
		{
			data->scene->player.pos.x = new_x;
			data->scene->player.pos.y = new_y;
			printf("Movido a (%f, %f)\n", data->scene->player.pos.x, data->scene->player.pos.y);
		}
		else
			printf("Movimiento bloqueado hacia adelante\n");
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_S))
	{
		new_x = data->scene->player.pos.x - data->scene->player.dir.x * move_speed;
		new_y = data->scene->player.pos.y - data->scene->player.dir.y * move_speed;
		if (!is_wall(data, new_x, new_y))
		{
			data->scene->player.pos.x = new_x;
			data->scene->player.pos.y = new_y;
		}
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_A))
	{
		new_x = data->scene->player.pos.x - data->scene->player.plane.x * move_speed;
		new_y = data->scene->player.pos.y - data->scene->player.plane.y * move_speed;
		if (!is_wall(data, new_x, new_y))
		{
			data->scene->player.pos.x = new_x;
			data->scene->player.pos.y = new_y;
		}
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_D))
	{
		new_x = data->scene->player.pos.x + data->scene->player.plane.x * move_speed;
		new_y = data->scene->player.pos.y + data->scene->player.plane.y * move_speed;
		if (!is_wall(data, new_x, new_y))
		{
			data->scene->player.pos.x = new_x;
			data->scene->player.pos.y = new_y;
		}
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_LEFT))
	{
		data->scene->player.dir = rotate_vec2(data->scene->player.dir, -rotation_speed);
		data->scene->player.plane = rotate_vec2(data->scene->player.plane, -rotation_speed);
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_RIGHT))
	{
		data->scene->player.dir = rotate_vec2(data->scene->player.dir, rotation_speed);
		data->scene->player.plane = rotate_vec2(data->scene->player.plane, rotation_speed);
	}
}