/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:59:56 by adrian            #+#    #+#             */
/*   Updated: 2024/11/19 22:26:11 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	draw_minimap(mlx_t *mlx, t_mapData *map_data)
{
	int			mini_width;
	int			mini_height;
	int			x;
	int			y;
	int			i;
	int			j;
	float		scale_x;
	float		scale_y;
	mlx_image_t	*minimap;
	uint32_t	color;
	char		cell;

	mini_height = 100;
	mini_width = 100;
	scale_x = (float)mini_width / map_data->width;
	scale_y = (float)mini_height / map_data->height;
	minimap = mlx_new_image(mlx, mini_width, mini_height);
	if (!minimap)
		return;
	y = 0;
	x = 0;
	while (x < mini_width)
	{
		y = 0;
		while (y < mini_height)
		{
			mlx_put_pixel(minimap, x, y, 0x000000FF);
			y++;
		}
		x++;
	}
	x = 0;
	y = 0;
	while (y < map_data->height)
	{
		x = 0;
		while (x < map_data->width)
		{
			cell = map_data->map[y][x];
			if (cell == '1')
				color = 0x333333FF;
			else if (cell == '0')
				color = 0xFFFFFFAA;
			else if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
				color = 0x00FF00FF;
			else
			{
				x++;
				continue;
			}
			i = 0;
			while (i < (int)scale_x)
			{
				j = 0;
				while (j < (int)scale_y)
				{
					if ((x * scale_x + i) < minimap->width && (y * scale_y + j) < minimap->height)
						mlx_put_pixel(minimap, (x * scale_x) + i, (y * scale_y) + j, color);
					j++;
				}
				i++;
			}
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(mlx, minimap, mlx->width - mini_width - 10, 10) < 0)
		perror("Error al mostrar el minimapa en la ventana");
}
