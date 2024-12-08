/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:57:16 by adrian            #+#    #+#             */
/*   Updated: 2024/12/06 19:46:20 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "functions.h"
#include "include/cub3d.h"

bool	is_wall(t_data *data, float x, float y)
{
	int	map_x;
	int	map_y;

	map_y = (int)(y / 10);
	map_x = (int)(x / 10);
	if (map_x < 0 || map_x >= data->colsx || map_y < 0 || map_y >= data->rowsy)
		return true;
	return data->scene->map[map_y][map_x] == '1';
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
	rotation_speed = 0.05;
	ft_memset(&move, 0, sizeof(t_vec2));
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_ESCAPE))
	{
		printf("ESC pressed\n");
		exit(0);
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_W))
	{
		printf("W pressed\n");
		move.x += data->scene->player.dir.x * move_speed;
		move.y += data->scene->player.dir.y * move_speed;
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_S))
	{
		move.x -= data->scene->player.dir.x * move_speed;
		move.y -= data->scene->player.dir.y * move_speed;
		printf("S pressed\n");
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_A))
	{
		move.x -= data->scene->player.plane.x * move_speed;
		move.y -= data->scene->player.plane.y * move_speed;
		printf("A pressed\n");
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_D))
	{
		move.x += data->scene->player.plane.x * move_speed;
		move.y += data->scene->player.plane.y * move_speed;
		printf("D pressed\n");
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_LEFT))
	{
		data->scene->player.dir = rotate_vec2(data->scene->player.dir, -rotation_speed);
		data->scene->player.plane = rotate_vec2(data->scene->player.plane, -rotation_speed);
		printf("Left arrow pressed\n");
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_RIGHT))
	{
		data->scene->player.dir = rotate_vec2(data->scene->player.dir, rotation_speed);
		data->scene->player.plane = rotate_vec2(data->scene->player.plane, rotation_speed);
		printf("Right arrow pressed\n");
	}
	new_y = data->scene->player.pos.y + move.y;
	new_x = data->scene->player.pos.x + move.x;
	if (!is_wall(data, new_x, new_y)) {
        data->scene->player.pos.x = new_x;
        data->scene->player.pos.y = new_y;
    }
}