/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moha <moha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:15:17 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/27 14:14:52 by moha             ###   ########.fr       */
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
            dest[j] = '0';
        else
            dest[j] = src[j];
        j++;
    }
    dest[len] = '\0';
}

void free_scene_map(t_scene *scene, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(scene->map[i]);
    }
    free(scene->map);
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
			free_data(data->parser, data, scene);
			return ;
		}
		copy_and_replace(scene->map[i], data->map[i], len);
		scene->map[i][len] = '\0';
		i++;
	}
	scene->rows = data->rowsy;
}

// void resize_map(t_scene *scene, int nuevas_filas, int nuevas_columnas)
// {

// }

void	set_scene(t_scene *scene, t_parser parser, t_data *data)
{
	calc_x_y(data);
	scene->rows = data->rowsy;
	scene->cols = data->colsx;
	parse_scene(scene, data);
	scene->map = padding_map(scene->map, &scene->rows, &scene->cols);
	// print_map(scene->map, 25);
	scene->player = set_player(scene->map);
	set_mlx(scene, parser, data);
	if (scene->map == NULL)
	{
		free_data(&parser, data, scene);
		exit(0);
	}
}

char	**padding_map(char **map, int *rows, int *cols)
{
	char	**new_map;
	int		i;

	// delete_enter(map);
	*rows += 10 * 2;
	*cols += 10 * 2;
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
		if (i >= 10 && i < *rows - 10)
		{
			ft_strlcpy(new_map[i] + 10 - 2, map[i - 10], *cols + 1);
		}
		new_map[i][*cols] = '\0';
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
