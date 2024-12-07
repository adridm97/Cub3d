/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:59:56 by adrian            #+#    #+#             */
/*   Updated: 2024/12/07 15:35:11 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	init_minimap(t_data *data)
{
	int	mini_width;
	int	mini_height;

	mini_height = 550;
	mini_width = 550;

	data->minimap.width = mini_width;
	data->minimap.height = mini_height;
	data->minimap.scale_x = (float)mini_width / data->scene->cols;
	data->minimap.scale_y = (float)mini_height / data->scene->rows;
	data->minimap.img = mlx_new_image(data->scene->mlx, \
		data->minimap.width, data->minimap.height);
	if (!data->minimap.img)
	{
		// usar nuestra funcion 
		fprintf(stderr, "Error: could not create minimap image\n");
		exit(1);
	}
}

void clear_minimap(t_data *data)
{

    for (int y = 0; y < data->scene->cols; y++)
    {
        for (int x = 0; x < data->scene->rows; x++)
        {
            mlx_put_pixel(data->minimap.img, x, y, 0x000000FF); // Negro para limpiar
        }
    }
}

void	draw_minimap(t_data *data)
{
	clear_minimap(data);
    for (int y = 0; y < data->scene->rows; y++)
    {
        for (int x = 0; x < data->scene->cols; x++)
        {
            if (data->scene->map[y][x] == '1') // Pared
            {
                int draw_x = x * data->minimap.scale_x;
                int draw_y = y * data->minimap.scale_y;
                for (int i = 0; i < data->minimap.scale_x; i++)
                {
                    for (int j = 0; j < data->minimap.scale_y; j++)
                    {
                        mlx_put_pixel(data->minimap.img, draw_x + i, draw_y + j, 0xFFFFFFFF);
                    }
                }
            }
        }
    }
    int player_x = data->scene->player.pos.x * data->minimap.scale_x;
    int player_y = data->scene->player.pos.y * data->minimap.scale_y;
	int player_size = 5;
	for (int i = 0; i < player_size; i++)
	{
		for (int j = 0; j < player_size; j++)
		{
			mlx_put_pixel(data->minimap.img, player_x + i, player_y + j, 0xFF0000FF);
		}
	}
	// mlx_put_pixel(data->minimap.img, player_x, player_y, 0xFF0000FF);
	mlx_image_to_window(data->scene->mlx, data->minimap.img, 550, 300);
}

void	my_mlx_pixel_put(t_minimap *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
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
