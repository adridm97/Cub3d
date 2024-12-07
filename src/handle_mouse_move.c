/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mouse_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:26:47 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/07 23:29:35 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void handle_mouse_move(double x, double y, void *param)
{
    static int last_x = -1;
    t_data *data = (t_data *)param;

    if (last_x == -1)
    {
        last_x = x;
        return;
    }
    (void)y;
    int delta_x = x - last_x;
    last_x = x;

    float rotation_speed = 0.002;
    float angle = delta_x * rotation_speed;

    float old_dir_x = data->scene->player.dir.x;

	data->scene->player.dir.x = data->scene->player.dir.x * \
	cos(angle) - data->scene->player.dir.y * sin(angle);
	data->scene->player.dir.y = old_dir_x * \
		sin(angle) + data->scene->player.dir.y * cos(angle);
}