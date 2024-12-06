/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:59:56 by adrian            #+#    #+#             */
/*   Updated: 2024/12/06 19:36:26 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "functions.h"
#include "include/cub3d.h"

// void	draw_minimap(mlx_t *mlx, t_mapData *map_data)
// {
// 	int			mini_width;
// 	int			mini_height;
// 	int			x;
// 	int			y;
// 	int			i;
// 	int			j;
// 	float		scale_x;
// 	float		scale_y;
// 	mlx_image_t	*minimap;
// 	uint32_t	color;
// 	char		cell;

// 	mini_height = 100;
// 	mini_width = 100;
// 	scale_x = (float)mini_width / map_data->width;
// 	scale_y = (float)mini_height / map_data->height;
// 	minimap = mlx_new_image(mlx, mini_width, mini_height);
// 	if (!minimap)
// 		return;
// 	y = 0;
// 	x = 0;
// 	while (x < mini_width)
// 	{
// 		y = 0;
// 		while (y < mini_height)
// 		{
// 			mlx_put_pixel(minimap, x, y, 0x000000FF);
// 			y++;
// 		}
// 		x++;
// 	}
// 	x = 0;
// 	y = 0;
// 	while (y < map_data->height)
// 	{
// 		x = 0;
// 		while (x < map_data->width)
// 		{
// 			cell = map_data->map[y][x];
// 			if (cell == '1')
// 				color = 0x333333FF;
// 			else if (cell == '0')
// 				color = 0xFFFFFFAA;
// 			else if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
// 				color = 0x00FF00FF;
// 			else
// 			{
// 				x++;
// 				continue;
// 			}
// 			i = 0;
// 			while (i < (int)scale_x)
// 			{
// 				j = 0;
// 				while (j < (int)scale_y)
// 				{
// 					if ((x * scale_x + i) < minimap->width && (y * scale_y + j) < minimap->height)
// 						mlx_put_pixel(minimap, (x * scale_x) + i, (y * scale_y) + j, color);
// 					j++;
// 				}
// 				i++;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	if (mlx_image_to_window(mlx, minimap, mlx->width - mini_width - 10, 10) < 0)
// 		perror("Error al mostrar el minimapa en la ventana");
// }

// void init_minimap(t_data *data)
// {
// 	int mini_width;
// 	int mini_height;

// 	mini_height = 400;
// 	mini_width = 400;

// 	data->minimap.img = mlx_new_image(data->scene->mlx, mini_width, mini_height);
// 	if (!data->minimap.img)
// 	{
// 		printf("Error al crear la imagen del minimapa\n");
// 		exit(1);
// 	}

// 	data->minimap.width = mini_width;
// 	data->minimap.height = mini_height;
// 	data->minimap.scale_x = (float)mini_width / data->scene->cols;
// 	data->minimap.scale_y = (float)mini_height / data->scene->rows;
// }

void	init_minimap(t_data *data)
{
	data->minimap.width = data->colsx * 10;
	data->minimap.height = data->rowsy * 10;
	data->minimap.img = mlx_new_image(data->scene->mlx, data->minimap.width, data->minimap.height);
	if (!data->minimap.img)
	{
		fprintf(stderr, "Error: No se pudo crear la imagen para el minimapa\n");
		exit(EXIT_FAILURE);
	}
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;
	int	color;
    int	rect_width;
    int	rect_height;

	rect_height = data->minimap.scale_y * 2;
	rect_width = data->minimap.scale_x * 2;
    for (y = 0; y < data->rowsy; y++) {
        for (x = 0; x < data->colsx; x++) {
            if (data->scene->map[y][x] == '1')
            {
                color = 0xFFFFFFFF; // Color blanco para las paredes
            }
            else if (data->scene->map[y][x] == '0')
            {
                color = 0xFFFF0000;
            }
            else
                continue; // Color negro para el espacio vacío

            // int mini_x = x * data->minimap.scale_x;
            // int mini_y = y * data->minimap.scale_y;
            for (int i = 0; i < rect_width; i++)
			{
                for (int j = 0; j < rect_height; j++)
                    mlx_put_pixel(data->minimap.img, x * rect_width + j, y * rect_height + i, color);
            }
        }
    }
}

void	my_mlx_pixel_put(t_minimap *img, int x, int y, int color)
{
	char *dst;
	
	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void draw_player_on_minimap(t_data *data)
{
    int player_x;
    int player_y;
    // int player_size = 2; // Tamaño del jugador en el minimapa
    // int x, y;
    int color = 0xFF0000FF;

	player_x = data->scene->player.pos.x / data->minimap.scale_x;
	player_y = data->scene->player.pos.y / data->minimap.scale_y;
	for (int i = 0; i < data->minimap.scale_y; i++)
	{
		for (int j = 0; j < data->minimap.scale_x; j++)
			my_mlx_pixel_put(&data->minimap, player_x * data->minimap.scale_x + j, player_y * data->minimap.scale_y + i, color);
	}
}