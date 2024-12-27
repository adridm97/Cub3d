/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:39:56 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/27 18:05:36 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	close_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	handle_exit(data);
}

void	cleanup(t_data *data)
{
	if (!data)
		return ;
	if (data->minimap.img)
		mlx_delete_image(data->scene->mlx, data->minimap.img);
	if (data->image)
		mlx_delete_image(data->scene->mlx, data->image);
	if (data->scene->mlx)
		mlx_terminate(data->scene->mlx);
}

void	free_mlx(t_scene *scene, t_parser *parser)
{
	(void)scene;
	free_string(parser->elem.no);
	free_string(parser->elem.so);
	free_string(parser->elem.we);
	free_string(parser->elem.ea);
	free_string(parser->elem.f);
	free_string(parser->elem.c);
}

void	free_map(char **map, int size)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < size)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}
