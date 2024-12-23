/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:26:47 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/23 18:26:00 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	handle_mouse_move(double x, double y, void *param)
{
	static int	last_x;
	int			delta_x;
	float		rotation_speed;
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
	rotation_speed = 0.002;
	angle = delta_x * rotation_speed;
	old_dir_x = data->scene->player.dir.x;
	data->scene->player.dir.x = data->scene->player.dir.x * \
	cos(angle) - data->scene->player.dir.y * sin(angle);
	data->scene->player.dir.y = old_dir_x * \
		sin(angle) + data->scene->player.dir.y * cos(angle);
}
