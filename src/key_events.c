/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:57:16 by adrian            #+#    #+#             */
/*   Updated: 2024/12/27 14:35:10 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	handle_forward_backward(t_data *data, t_key key_w, t_key key_s)
{
	t_vec2	new_pos;
	t_vec2	direction;

	new_pos = data->scene->player.pos;
	if (key_w.curr)
	{
		direction.x = data->scene->player.dir.x * MOVE_SPEED;
		direction.y = data->scene->player.dir.y * MOVE_SPEED;
	}
	else if (key_s.curr)
	{
		direction.x = -data->scene->player.dir.x * MOVE_SPEED;
		direction.y = -data->scene->player.dir.y * MOVE_SPEED;
	}
	else
		return ;
	new_pos = sum_vec2(new_pos, direction);
	if (!is_wall(data, new_pos.x, new_pos.y))
		data->scene->player.pos = new_pos;
}

void	handle_strafe(t_data *data, t_key key_a, t_key key_d)
{
	t_vec2	new_pos;
	t_vec2	direction;

	new_pos = data->scene->player.pos;
	if (key_a.curr)
	{
		direction.x = -data->scene->player.plane.x * MOVE_SPEED;
		direction.y = -data->scene->player.plane.y * MOVE_SPEED;
	}
	else if (key_d.curr)
	{
		direction.x = data->scene->player.plane.x * MOVE_SPEED;
		direction.y = data->scene->player.plane.y * MOVE_SPEED;
	}
	else
		return ;
	new_pos = sum_vec2(new_pos, direction);
	if (!is_wall(data, new_pos.x, new_pos.y))
		data->scene->player.pos = new_pos;
}

void	handle_rotation(t_data *data, t_key key_left, t_key key_right)
{
	if (key_left.curr)
	{
		data->scene->player.dir = rotate_vec2(data->scene->player.dir, \
		-ROTATION_SPEED);
		data->scene->player.plane = rotate_vec2(data->scene->player.plane, \
		-ROTATION_SPEED);
	}
	else if (key_right.curr)
	{
		data->scene->player.dir = rotate_vec2(data->scene->player.dir, \
		ROTATION_SPEED);
		data->scene->player.plane = rotate_vec2(data->scene->player.plane, \
		ROTATION_SPEED);
	}
}

void	key_hook(t_data *data)
{
	t_keys	*key;

	key = data->key;
	update_keys(key, data->scene->mlx);
	if (key_pressed(key->esc))
		handle_exit(data);
	if (key_held(key->w) || key_held(key->s))
		handle_forward_backward(data, key->w, key->s);
	if (key_held(key->a) || key_held(key->d))
		handle_strafe(data, key->a, key->d);
	if (key_held(key->left) || key_held(key->right))
		handle_rotation(data, key->left, key->right);
}
