/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:18:28 by aduenas-          #+#    #+#             */
/*   Updated: 2024/12/26 17:36:27 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_textures(t_textures textures, t_data *data)
{
	if (textures.north && textures.img_n)
	{
		mlx_delete_texture(textures.north);
		mlx_delete_image(data->scene->mlx, textures.img_n);
	}
	if (textures.south)
	{
		mlx_delete_texture(textures.south);
		mlx_delete_image(data->scene->mlx, textures.img_s);
	}
	if (textures.east)
	{
		mlx_delete_texture(textures.east);
		mlx_delete_image(data->scene->mlx, textures.img_e);
	}
	if (textures.west)
	{
		mlx_delete_texture(textures.west);
		mlx_delete_image(data->scene->mlx, textures.img_w);
	}
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

void	handle_exit(t_data *data)
{
	if (data)
	{
		cleanup(data);
		free_textures(data->textures, data);
	}
	printf("Saliendo del juego...\n");
	mlx_delete_image(data->scene->mlx, data->image);
	mlx_terminate(data->scene->mlx);
	free_data(data->parser, data, data->scene);
	exit(0);
}
