/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:15:17 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/27 14:39:19 by adrian           ###   ########.fr       */
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
		printf("%s\n", map[i]);
}

void	set_scene(t_scene *scene, t_parser parser, t_data *data)
{
	calc_x_y(data);
	scene->rows = data->rowsy;
	scene->cols = data->colsx;
	scene->map = padding_map(data->map, &scene->rows, &scene->cols);
	scene->player = set_player(scene->map);
	set_mlx(scene, parser, data);
	if (scene->map == NULL)
	{
		free_data(&parser, data, scene);
		exit(0);
	}
	if (!data->key)
	{
		data->key = malloc(sizeof(t_keys));
		if (!data->key)
		{
			free_data(&parser, data, scene);
			perror("Error al asignar memoria para data->key");
			exit(1);
		}
	}
	ft_memset(data->key, 0, sizeof(t_keys));
}

char	**padding_map(char **map, int *rows, int *cols)
{
	char	**new_map;
	int		i;

	delete_enter(map);
	*rows += 20 * 2;
	*cols += 20 * 2;
	new_map = malloc(sizeof(char *) * (*rows + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < *rows)
	{
		new_map[i] = malloc(sizeof(char) * (*cols + 1));
		if (!new_map[i])
			return (ft_free_game(new_map), NULL);
		ft_memset(new_map[i], ' ', *cols + 1);
		if (i >= 20 && i < *rows - 20)
			ft_strlcpy(new_map[i] + 20 - 2, map[i - 20], *cols + 1);
		new_map[i][*cols] = '\0';
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
