/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:57:16 by adrian            #+#    #+#             */
/*   Updated: 2024/11/30 16:31:12 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "functions.h"
#include "include/cub3d.h"

t_vec2	sum_vec2(t_vec2 v1, t_vec2 v2)
{
	t_vec2	v;

	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	return (v);
}

void key_hook(t_data *data)
{
	t_vec2 move;

	ft_memset(&move, 0, sizeof(t_vec2));
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_ESCAPE))
	{
		printf("ESC pressed\n");
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_W))
	{
		// printf("W pressed\n");
		move.x += data->scene->player.dir.x * 0.1f;
		move.y += data->scene->player.dir.y * 0.1f;
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_S))
	{
		move.x -= data->scene->player.dir.x * 0.1f;
		move.y -= data->scene->player.dir.y * 0.1f;
		// printf("S pressed\n");
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_A))
	{
		move.x -= data->scene->player.dir.x * 0.1f;
		move.y += data->scene->player.dir.y * 0.1f;
		// printf("A pressed\n");
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_D))
	{
		move.x += data->scene->player.dir.x * 0.1f;
		move.y -= data->scene->player.dir.y * 0.1f;
		// printf("D pressed\n");
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_LEFT))
	{
		move.x += data->scene->player.dir.x * 0.1f;
		move.y += data->scene->player.dir.y * 0.1f;
		// printf("Left arrow pressed\n");
	}
	else if (mlx_is_key_down(data->scene->mlx, MLX_KEY_RIGHT))
	{
		move.x += data->scene->player.dir.x * 0.1f;
		move.y += data->scene->player.dir.y * 0.1f;
		// printf("Right arrow pressed\n");
	}
	data->scene->player.pos = sum_vec2(data->scene->player.pos, move);
}