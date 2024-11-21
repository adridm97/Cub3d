/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:18:50 by aduenas-          #+#    #+#             */
/*   Updated: 2024/11/19 22:50:21 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

uint32_t getColor(t_color color)
{
	if (color.r < 0 || color.r > 255 || color.g < 0 || color.g > 255 || color.b < 0 || color.b > 255)
	{
    	perror("Error: Color inválido.\n");
    		return 0;
	}
    return (color.r << 24 | color.g << 16 | color.b << 8 | 255);
}

void	drawBackground(mlx_t *mlx, t_mapData *map_data)
{
	int			y;
	int			x;
	int			width;
	int			height;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	mlx_image_t	*img;

	width = mlx->width;
	height = mlx->height;
	img = mlx_new_image(mlx, width, height);
	if (!img)
		return ;
	y = 0;
	ceiling_color = getColor(map_data->ceiling);
	floor_color = getColor(map_data->floor);
	if (ceiling_color == 0 || floor_color  == 0)
		return ;
	while (y < height / 2)
	{
		x = 0;
		while ( x < width)
		{
			mlx_put_pixel(img, x, y, ceiling_color);
			x++;
		}
		y++;
	}
	y = height / 2;
	while ( y < height)
	{
		x = 0;
		while ( x < width)
		{
			mlx_put_pixel(img, x, y, floor_color);
			x++;
		}
		y++;
	}
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	{
		perror("Error al mostrar la imagen en la ventana");
		return;
	}
}

int	main(int argc, char **argv)
{
	mlx_t		*mlx;
	mlx_image_t *image;
	int			fd;
	t_mapData	map_data = {0};

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			perror("Error al abrir el archivo");
			return (1);
		}
		map_data.width = 0;
		map_data.height = 0;
		parse_file(fd, &map_data, argv[1]);
		close(fd);
		mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", 1);
		if (!mlx)
        	return (1);
		image = mlx_new_image(mlx, WIDTH, HEIGHT);
		if (!image)
		{
			fprintf(stderr, "Error: No se pudo crear la imagen\n");
			exit(EXIT_FAILURE);
		}
		drawBackground(mlx, &map_data);
		printf("1\n");
		draw_walls(mlx, image, &map_data);
		draw_minimap(mlx, &map_data);
		printf("2\n");
		mlx_key_hook(mlx, key_hook, &map_data);
		printf("3\n");
		mlx_loop(mlx);
		mlx_terminate(mlx);
		return (0);
	}
	else
	{
		perror("Invalid arguments, need a .map");
		return (1);
	}
}
