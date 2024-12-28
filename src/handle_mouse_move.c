/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:26:47 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/28 12:29:20 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	rotate(t_data *data, double angle)
{
	float	plane;
	float	old_dir_x;

	old_dir_x = data->scene->player.dir.x;
	data->scene->player.dir.x = data->scene->player.dir.x * cos(angle)
		- data->scene->player.dir.y * sin(angle);
	data->scene->player.dir.y = old_dir_x * sin(angle)
		+ data->scene->player.dir.y * cos(angle);
	plane = data->scene->player.plane.x;
	data->scene->player.plane.x = data->scene->player.plane.x * cos(angle) \
		- data->scene->player.plane.y * sin(angle);
	data->scene->player.plane.y = plane * sin(angle)
		+ data->scene->player.plane.y * cos(angle);
}

void	handle_mouse_move(double x, double y, void *param)
{
	static int	last_x = -1;
	int			delta_x;
	float		angle;
	t_data		*data;

	(void)y;
	data = (t_data *)param;
	if (last_x == -1)
	{
		last_x = x;
		return ;
	}
	delta_x = x - last_x;
	last_x = x;
	angle = delta_x * 0.005f;
	rotate(data, angle);
}

void	draw_player_minimap(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->minimap.player_size)
	{
		j = -1;
		while (++j < data->minimap.player_size)
		{
			mlx_put_pixel(data->minimap.img, data->minimap.player_x + i,
				data->minimap.player_y + j, 0xFF0000FF);
		}
	}
}

void	draw_pixel_block(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->minimap.scale_x)
	{
		j = -1;
		while (++j < data->minimap.scale_y)
		{
			mlx_put_pixel(data->minimap.img, data->minimap.draw_x + i,
				data->minimap.draw_y + j, 0xFFFFFFFF);
		}
	}
}
