/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:28:30 by adrian            #+#    #+#             */
/*   Updated: 2024/12/27 19:16:05 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	render(void *scene_keys)
{
	t_data	*data;

	data = (t_data *)scene_keys;
	if (!data || !data->scene || !data->image)
	{
		perror("Error: Datos de escena no inicializados correctamente.\n");
		return ;
	}
	key_hook(data);
	draw_background(data->image, data->scene);
	draw_walls(data, data->scene);
	draw_minimap(data);
}

void	draw_background(mlx_image_t *image, t_scene *scene)
{
	int			y;
	int			x;
	static int	first_time = 0;

	handle_errors_background(image, scene);
	y = -1;
	while (++y < HEIGHT / 2)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(image, x, y, scene->ccolor);
	}
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			mlx_put_pixel(image, x, y, scene->fcolor);
	}
	if (first_time == 0)
	{
		first_time = 1;
		if (mlx_image_to_window(scene->mlx, image, 0, 0) < 0)
			exit(1);
	}
}

void	draw_walls(t_data *data, t_scene *scene)
{
	mlx_image_t	*texture;

	texture = NULL;
	validate_scene_and_data(data, scene);
	draw_walls_loop(data, texture);
}
