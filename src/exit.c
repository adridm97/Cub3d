/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moha <moha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:18:28 by aduenas-          #+#    #+#             */
/*   Updated: 2024/12/24 00:44:56 by moha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_textures(t_textures textures)
{
	if (textures.north)
		mlx_delete_texture(textures.north);
	if (textures.south)
		mlx_delete_texture(textures.south);
	if (textures.east)
		mlx_delete_texture(textures.east);
	if (textures.west)
		mlx_delete_texture(textures.west);
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
		free_textures(data->textures);
	}
	printf("Saliendo del juego...\n");
	mlx_delete_image(data->scene->mlx, data->image);
	mlx_terminate(data->scene->mlx);
	exit(0);
}
