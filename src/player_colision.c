/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_colision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:35:00 by adrian            #+#    #+#             */
/*   Updated: 2024/12/28 18:22:24 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_wall(t_data *data, double x, double y)
{
	int	check_x;
	int	check_y;

	check_x = (int)x;
	check_y = (int)y;
	if (check_x < 0 || check_x >= data->scene->cols || check_y < 0 || \
	check_y >= data->scene->rows)
		return (1);
	if (data->scene->map[check_y][check_x] == '1')
		return (1);
	check_x = (int)(x - PLAYER_PADDING - 1);
	while (++check_x <= (int)(x + PLAYER_PADDING))
	{
		check_y = (int)(y - PLAYER_PADDING - 1);
		while (++check_y <= (int)(y + PLAYER_PADDING))
		{
			if (check_x >= 0 && check_x < data->scene->cols && check_y >= 0 && \
			check_y < data->scene->rows)
			{
				if (data->scene->map[check_y][check_x] == '1')
					return (1);
			}
		}
	}
	return (0);
}

int	check_collision(t_data *data, t_vec2 new_pos)
{
	float	radius;

	radius = 5.0f;
	if (new_pos.x < 0 || new_pos.y < 0 || new_pos.y >= HEIGHT || \
	new_pos.x >= WIDTH)
		return (1);
	if (is_wall(data, new_pos.x - radius, new_pos.y - radius) || \
		is_wall(data, new_pos.x + radius, new_pos.y - radius) || \
		is_wall(data, new_pos.x - radius, new_pos.y + radius) || \
		is_wall(data, new_pos.x + radius, new_pos.y + radius))
		return (1);
	return (0);
}
