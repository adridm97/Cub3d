/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_colision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:35:00 by adrian            #+#    #+#             */
/*   Updated: 2024/12/23 18:39:08 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_wall(t_data *data, int x, int y)
{
	(void)x;
	(void)y;
	if (data->scene->map[y][x] == '1')
		return (true);
	return (false);
}

bool	check_collision(t_data *data, t_vec2 new_pos)
{
	float	radius;

	radius = 5.0f;
	if (new_pos.x < 0 || new_pos.y < 0 || new_pos.y >= HEIGHT || \
	new_pos.x >= WIDTH)
		return (true);
	if (is_wall(data, new_pos.x - radius, new_pos.y - radius) || \
		is_wall(data, new_pos.x + radius, new_pos.y - radius) || \
		is_wall(data, new_pos.x - radius, new_pos.y + radius) || \
		is_wall(data, new_pos.x + radius, new_pos.y + radius))
		return (true);
	return (false);
}
