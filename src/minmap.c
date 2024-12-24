/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moha <moha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:59:56 by adrian            #+#    #+#             */
/*   Updated: 2024/12/24 00:56:02 by moha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_minimap(t_data *data)
{
	int	mini_width;
	int	mini_height;

	mini_height = 550;
	mini_width = 550;
	data->minimap.width = mini_width;
	data->minimap.height = mini_height;
	data->minimap.scale_x = (float)mini_width / (float)data->scene->cols;
	data->minimap.scale_y = (float)mini_height / (float)data->scene->rows;
	data->minimap.img = mlx_new_image(data->scene->mlx, \
		data->minimap.width, data->minimap.height);
	if (!data->minimap.img)
	{
		fprintf(stderr, "Error: could not create minimap image\n");
		exit(1);
	}
}

void	clear_minimap(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->minimap.height)
	{
		x = 0;
		while (x < data->minimap.width)
		{
			mlx_put_pixel(data->minimap.img, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	int	y;
	int	x;
	int	j;
	int	i;

	data->minimap.player_x = data->scene->player.pos.x * data->minimap.scale_x;
	data->minimap.player_y = data->scene->player.pos.y * data->minimap.scale_y;
	data->minimap.player_size = 5;
	y = -1;
	while (++y < data->scene->rows)
	{
		x = -1;
		while (++x < data->scene->cols)
		{
			if (data->scene->map[y][x] == '1')
			{
				data->minimap.draw_x = x * data->minimap.scale_x;
				data->minimap.draw_y = y * data->minimap.scale_y;
				i = -1;
				while (++i < data->minimap.scale_x)
				{
					j = -1;
					while (++j < data->minimap.scale_y)
					{
						mlx_put_pixel(data->minimap.img, data->minimap.draw_x + \
						i, data->minimap.draw_y + j, 0xFFFFFFFF);
					}
				}
			}
		}
	}
	draw_player_minimap(data);
	mlx_image_to_window(data->scene->mlx, data->minimap.img, 550, 300);
}

void	my_mlx_pixel_put(t_minimap *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_player_on_minimap(t_data *data)
{
	int	player_x;
	int	player_y;
	int	color;
	int	i;
	int	j;

	color = 0xFF0000FF;
	i = 0;
	player_x = data->scene->player.pos.x / data->minimap.scale_x;
	player_y = data->scene->player.pos.y / data->minimap.scale_y;
	while (i < data->minimap.scale_y)
	{
		j = 0;
		while (j < data->minimap.scale_x)
		{
			my_mlx_pixel_put(&data->minimap, \
				player_x * data->minimap.scale_x + j, \
				player_y * data->minimap.scale_y + i, color);
			j++;
		}
		i++;
	}
}
