/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:03:11 by adrian            #+#    #+#             */
/*   Updated: 2024/12/21 11:12:46 by adrian           ###   ########.fr       */
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
		printf("Error al cargar textura %s: %s\n", name, trimmed_path);
	free(trimmed_path);
	return texture;
}

void	init_textures(t_data *data)
{
	data->scene->textures = malloc(sizeof(mlx_texture_t *) * 4);
	data->scene->textures[0] = load_texture(data->parser->elem.no, "norte");
	data->scene->textures[1] = load_texture(data->parser->elem.so, "sur");
	data->scene->textures[2] = load_texture(data->parser->elem.ea, "este");
	data->scene->textures[3] = load_texture(data->parser->elem.we, "oeste");
}
void	calculate_wall_x(t_wall *walls, t_data *data, mlx_texture_t *texture)
{
	if (walls->side == 0)
		walls->wall_x = data->scene->player.pos.y + walls->perp_wall_dist * walls->ray_dir_y;
	else
		walls->wall_x = data->scene->player.pos.x + walls->perp_wall_dist * walls->ray_dir_x;
	walls->wall_x = fmod(walls->wall_x, 1.0);
	if (walls->wall_x < 0)
		walls->wall_x += 1.0;
	walls->tex_x = (int)(walls->wall_x * (double)texture->width);
	if (walls->tex_x < 0)
		walls->tex_x = 0;
	if (walls->tex_x >= (int)texture->width)
		walls->tex_x = texture->width - 1;
	if ((walls->side == 0 && walls->ray_dir_x < 0) || (walls->side == 1 && walls->ray_dir_y > 0))
		walls->tex_x = texture->width - walls->tex_x - 1;
}

mlx_texture_t	*select_texture(t_wall *walls, t_data *data)
{
	mlx_texture_t *texture;

	if (walls->side == 0)
	{
		if (walls->ray_dir_x > 0)
			texture = data->scene->textures[0];
		else
			texture = data->scene->textures[1];
	}
	else
	{
		if (walls->ray_dir_y > 0)
			texture = data->scene->textures[2];
		else
			texture = data->scene->textures[3];
	}
	calculate_wall_x(walls, data, texture);
	return (texture);
}
