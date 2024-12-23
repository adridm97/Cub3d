/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:57:16 by adrian            #+#    #+#             */
/*   Updated: 2024/12/23 20:25:41 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	data->scene->player.pos = new_pos;
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
	data->scene->player.pos = new_pos;
}

void	handle_rotation(t_data *data)
{
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_LEFT))
	{
		data->scene->player.dir = rotate_vec2(data->scene->player.dir, \
		-ROTATION_SPEED);
		data->scene->player.plane = rotate_vec2(data->scene->player.plane, \
		-ROTATION_SPEED);
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_RIGHT))
	{
		data->scene->player.dir = rotate_vec2(data->scene->player.dir, \
		ROTATION_SPEED);
		data->scene->player.plane = rotate_vec2(data->scene->player.plane, \
		ROTATION_SPEED);
	}
}

void	key_hook(t_data *data)
{
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_ESCAPE))
		handle_exit(data);
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_W) || \
	mlx_is_key_down(data->scene->mlx, MLX_KEY_S))
		handle_forward_backward(data);
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_A) || \
	mlx_is_key_down(data->scene->mlx, MLX_KEY_D))
		handle_strafe(data);
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_LEFT) || \
	mlx_is_key_down(data->scene->mlx, MLX_KEY_RIGHT))
		handle_rotation(data);
}
