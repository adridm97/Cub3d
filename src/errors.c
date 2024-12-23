/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 22:54:07 by adrian            #+#    #+#             */
/*   Updated: 2024/12/22 20:58:15 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	handle_errors_background(mlx_image_t *image, t_scene *scene)
{
	if (scene->ccolor == 0 || scene->fcolor == 0)
	{
		printf("Error: Los colores del fondo no son válidos (ccolor: %x, fcolor: \
		%x).\n", scene->ccolor, scene->fcolor);
		return ;
	}
	if (!image)
	{
		printf("Error: La imagen no está inicializada.\n");
		return ;
	}
}

void	validate_scene_and_data(t_data *data, t_scene *scene)
{
	if (!scene || !scene->map || !data->image)
	{
		printf("Error: Datos de escena no válidos en draw_walls.\n");
		return ;
	}
}
