/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:15:17 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/28 18:03:07 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	set_mlx(t_scene *scene, t_parser parser, t_data *data)
{
	scene->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", 1);
	if (scene->mlx == NULL)
	{
		free_data(&parser, data, scene);
		exit(0);
	}
	data->image = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	if (data->image == NULL)
	{
		free_data(&parser, data, scene);
		exit(0);
	}
}

void	print_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		printf("%s\n", map[i++]);
}

void	copy_and_replace(char *dest, const char *src, size_t len)
{
	size_t	j;

	j = 0;
	while (j < len)
	{
		if (src[j] == ' ')
			dest[j] = '2';
		else
			dest[j] = src[j];
		j++;
	}
	dest[len] = '\0';
}

void	parse_scene(t_scene *scene, t_data *data)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	scene->map = malloc(sizeof(char *) * data->rowsy);
	if (scene->map == NULL)
		return ;
	while (i < data->rowsy)
	{
		len = ft_strlen(data->map[i]);
		scene->map[i] = malloc(sizeof(char) * (len + 1));
		if (scene->map[i] == NULL)
		{
			free_scene_map(scene->map, i);
			free_data(data->parser, data, scene);
			return ;
		}
		copy_and_replace(scene->map[i], data->map[i], len);
		scene->map[i][len] = '\0';
		i++;
	}
	scene->rows = data->rowsy;
}

void	set_scene(t_scene *scene, t_parser parser, t_data *data)
{

	calc_x_y(data);
	scene->rows = data->rowsy;
	scene->cols = data->colsx;
	parse_scene(scene, data);
	scene->map = padding_map(scene->map, &scene->rows, &scene->cols);
	scene->player = set_player(scene->map);
	set_mlx(scene, parser, data);
	if (scene->map == NULL)
	{
		free_data(&parser, data, scene);
		exit(0);
	}
	data->key = malloc(sizeof(t_keys));
	if (!data->key)
	{
		free_data(&parser, data, scene);
		perror("Error al asignar memoria para data->key");
		exit(1);
	}
	ft_memset(data->key, 0, sizeof(t_keys));
}
