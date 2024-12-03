/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:57:16 by adrian            #+#    #+#             */
/*   Updated: 2024/12/03 18:48:21 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "functions.h"
#include "include/cub3d.h"

void key_hook(t_data *data)
{	
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_ESCAPE))
	{
		printf("ESC pressed, exiting...\n");
		exit(0);
	}
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_W))
		printf("W pressed\n");
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_S))
		printf("S pressed\n");
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_A))
		printf("A pressed\n");
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_D))
		printf("D pressed\n");
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_LEFT))
		printf("Left arrow pressed\n");
	if (mlx_is_key_down(data->scene->mlx, MLX_KEY_RIGHT))
		printf("Right arrow pressed\n");
}