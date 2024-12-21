/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:57:16 by adrian            #+#    #+#             */
/*   Updated: 2024/12/21 16:35:45 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "functions.h"
#include "include/cub3d.h"

// bool	is_wall(t_data *data, float x, float y)
// {
// 	int	map_x;
// 	int	map_y;
// 	int	padding;

// 	map_y = (int)((y + (data->minimap.scale_y / 2)) / data->minimap.scale_y);
// 	map_x = (int)((x + (data->minimap.scale_x / 2)) / data->minimap.scale_x);
// 	if (map_x < 0 || map_x >= data->colsx || map_y < 0 || map_y >= data->rowsy)
// 		return true;
// 	if (data->scene->map[map_y][map_x] == '1')
// 		return true;
// 	padding = 1;
// 	if ((map_x + padding) < data->colsx && data->scene->map[map_y][map_x + padding] == '1')
// 		return true;
// 	if ((map_x - padding) >= 0 && data->scene->map[map_y][map_x - padding] == '1')
// 		return true;
// 	if ((map_y - padding) >= 0 && data->scene->map[map_y - padding][map_x] == '1')
// 		return true;
// 	if ((map_y + padding) < data->rowsy && data->scene->map[map_y + padding][map_x] == '1')
// 		return true;
// 	return false;
// }

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

void	handle_exit(t_data *data)
{
	if (data)
	{
		cleanup(data);
		free_textures(data);
	}
	printf("Saliendo del juego...\n");
	mlx_terminate(data->scene->mlx);
}

void	handle_forward_backward(t_data *data)
{
	t_vec2	new_pos;
	t_vec2	forward;
	t_vec2	backward;

	new_pos = data->scene->player.pos;
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_W))
	{
		forward.x = data->scene->player.dir.x * MOVE_SPEED;
		forward.y = data->scene->player.dir.y * MOVE_SPEED;
		new_pos = sum_vec2(new_pos, forward);
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_S))
	{
		backward.x = -data->scene->player.dir.x * MOVE_SPEED;
		backward.y = -data->scene->player.dir.y * MOVE_SPEED;
		new_pos = sum_vec2(new_pos, backward);
	}
	if (is_wall(data, new_pos.x, new_pos.y))
		return ;
	// printf("Nueva posición (forward/backward): (%f, %f)\n", new_pos.x, new_pos.y);
	// if (!check_collision(data, new_pos))
	// {
	data->scene->player.pos = new_pos;
	// 	printf("entra en el backward\n");
	// }
	// else
	// 	printf("hay colision en el backward\n");
}
void	handle_strafe(t_data *data)
{
	t_vec2	new_pos;
	t_vec2	left;
	t_vec2	right;

	new_pos = data->scene->player.pos;
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_A))
	{
		left.x = -data->scene->player.plane.x * MOVE_SPEED;
		left.y = -data->scene->player.plane.y * MOVE_SPEED;
		new_pos = sum_vec2(new_pos, left);
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_D))
	{
		right.x = data->scene->player.plane.x * MOVE_SPEED;
		right.y = data->scene->player.plane.y * MOVE_SPEED;
		new_pos = sum_vec2(new_pos, right);
	}
	if (is_wall(data, new_pos.x, new_pos.y))
		return ;
	// printf("Nueva posición (strafe): (%f, %f)\n", new_pos.x, new_pos.y);
	// if (!check_collision(data, new_pos))
	// {
	data->scene->player.pos = new_pos;
	// 	printf("entra en el strafe\n");
	// }
	// else
	// 	printf("hay colision strafe\n");
}
void	handle_rotation(t_data *data)
{
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_LEFT))
	{
		data->scene->player.dir = rotate_vec2(data->scene->player.dir, -ROTATION_SPEED);
		data->scene->player.plane = rotate_vec2(data->scene->player.plane, -ROTATION_SPEED);
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_RIGHT))
	{
		data->scene->player.dir = rotate_vec2(data->scene->player.dir, ROTATION_SPEED);
		data->scene->player.plane = rotate_vec2(data->scene->player.plane, ROTATION_SPEED);
	}
}

void	key_hook(t_data *data)
{
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_ESCAPE))
		handle_exit(data);
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_W) || mlx_is_key_down(data->scene->mlx, MLX_KEY_S))
		handle_forward_backward(data);
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_A) || mlx_is_key_down(data->scene->mlx, MLX_KEY_D))
		handle_strafe(data);
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_LEFT) || mlx_is_key_down(data->scene->mlx, MLX_KEY_RIGHT))
		handle_rotation(data);
}
