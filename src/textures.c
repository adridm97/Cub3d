/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:03:11 by adrian            #+#    #+#             */
/*   Updated: 2024/12/23 19:16:59 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static mlx_texture_t	*load_texture(const char *path, const char *name)
{
	char			*trimmed_path;
	mlx_texture_t	*texture;

	trimmed_path = ft_strtrim_ft(path, "\n");
	texture = mlx_load_png(trimmed_path);
	if (!texture)
	{
		printf("Error al cargar textura %s: %s\n", name, trimmed_path);
		free(trimmed_path);
		exit(1);
	}
	free(trimmed_path);
	return (texture);
}

void	init_textures(t_data *data)
{
	if (!data->textures)
	{
		data->textures = (t_textures *)malloc(sizeof(t_textures));
		if (!data->textures)
		{
			perror("Error al inicializar las texturas");
			exit(1);
		}
	}
	data->textures->north = load_texture(data->parser->elem.no, "norte");
	data->textures->south = load_texture(data->parser->elem.so, "sur");
	data->textures->east = load_texture(data->parser->elem.ea, "este");
	data->textures->west = load_texture(data->parser->elem.we, "oeste");
}

void	calculate_wall_x(t_wall *walls, t_data *data, mlx_texture_t *texture)
{
	if (walls->side == 0)
		walls->wall_x = data->scene->player.pos.y + walls->perp_wall_dist * \
		walls->ray_dir_y;
	else
		walls->wall_x = data->scene->player.pos.x + walls->perp_wall_dist * \
		walls->ray_dir_x;
	walls->wall_x = fmod(walls->wall_x, 1.0);
	if (walls->wall_x < 0)
		walls->wall_x += 1.0;
	walls->tex_x = (int)(walls->wall_x * (double)texture->width);
	if (walls->tex_x < 0)
		walls->tex_x = 0;
	if (walls->tex_x >= (int)texture->width)
		walls->tex_x = texture->width - 1;
	if ((walls->side == 0 && walls->ray_dir_x < 0) || (walls->side == 1 && \
	walls->ray_dir_y > 0))
		walls->tex_x = texture->width - walls->tex_x - 1;
}

mlx_texture_t	*select_texture(t_wall *walls, t_data *data)
{
	mlx_texture_t	*texture;

	if (walls->side == 0)
	{
		if (walls->ray_dir_x > 0)
			texture = data->textures->north;
		else
			texture = data->textures->south;
	}
	else
	{
		if (walls->ray_dir_y > 0)
			texture = data->textures->east;
		else
			texture = data->textures->west;
	}
	calculate_wall_x(walls, data, texture);
	return (texture);
}
