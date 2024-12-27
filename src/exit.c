/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:18:28 by aduenas-          #+#    #+#             */
/*   Updated: 2024/12/27 19:12:29 by aduenas-         ###   ########.fr       */
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
		if (data->scene && data->scene->map)
		{
			free_map(data->scene->map, data->scene->rows);
		}
		free_textures(data->textures, data);
	}
	printf("Saliendo del juego...\n");
	free_data(data->parser, data, data->scene);
	exit(0);
}

void	delete_enter(char **map)
{
	int	i;

	i = 0;
	while (map != NULL && map[i] != NULL)
	{
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
}
