/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moha <moha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:26:47 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/24 00:53:06 by moha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	handle_mouse_move(double x, double y, void *param)
{
	static int	last_x;
	int			delta_x;
	float		angle;
	float		old_dir_x;
	t_data		*data;

	(void)y;
	data = (t_data *)param;
	last_x = -1;
	if (last_x == -1)
	{
		last_x = x;
		return ;
	}
	delta_x = x - last_x;
	last_x = x;
	angle = delta_x * 0.002;
	old_dir_x = data->scene->player.dir.x;
	data->scene->player.dir.x = data->scene->player.dir.x * \
	cos(angle) - data->scene->player.dir.y * sin(angle);
	data->scene->player.dir.y = old_dir_x * \
		sin(angle) + data->scene->player.dir.y * cos(angle);
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
			mlx_put_pixel(data->minimap.img, data->minimap.player_x + i, \
				data->minimap.player_y + j, 0xFF0000FF);
		}
	}
}
