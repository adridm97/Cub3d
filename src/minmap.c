/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:59:56 by adrian            #+#    #+#             */
/*   Updated: 2024/12/28 18:02:39 by mel-atta         ###   ########.fr       */
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
		ft_putstr_fd("Error: could not create minimap image\n", 2);
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
			mlx_put_pixel(data->minimap.img, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data)
{
	int			y;
	int			x;
	static int	first_time = 0;

	clear_minimap(data);
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
				draw_pixel_block(data);
			}
		}
	}
	draw_player_minimap(data);
	put_image_window_once(data, first_time);
}

void	my_mlx_pixel_put(t_minimap *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}
