/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:16:33 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/29 20:05:33 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	**copy_map(t_parser parser, int y)
{
	char	**map;
	int		i;

	i = 0;
	if (y == 0)
		return (NULL);
	map = malloc(sizeof(char *) * (parser.rowsfile - y + 1));
	if (!map)
		return (NULL);
	while (parser.file[y] != NULL)
	{
		map[i] = ft_strdup(parser.file[y]);
		if (!map[i])
			return (free_map(map, i), NULL);
		y++;
		i++;
	}
	map[i] = NULL;
	return (map);
}

int	init_map(t_data *data, t_parser *parser)
{
	int		y;
	char	*trimed;
	int		is_map;

	y = 0;
	is_map = 0;
	parser->rowsfile = ft_rowsfile(parser->file);
	while (parser->file[y] != NULL)
	{
		trimed = ft_strtrim(parser->file[y], " ");
		if (trimed[0] == '1')
		{
			is_map = 1;
			break ;
		}
		y++;
		free(trimed);
	}
	if (is_map == 1)
		free(trimed);
	data->map = copy_map(*parser, y);
	return (0);
}

void	free_sc(t_scene *scene)
{
	int	y;

	y = 0;
	while (scene && scene->map && scene->map[y])
	{
		free(scene->map[y]);
		y++;
	}
	free(scene->map);
}

int	check_map(t_parser *parser, t_scene scene)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	if (check_player(scene.map, parser) == 1)
		return (1);
	while (scene.map != NULL && scene.map[y] != NULL)
	{
		if (scene.map[y][x] == '\0')
		{
			x = 0;
			y++;
		}
		else if (check_space(scene.map, x, y, parser->letter_player) == 1)
			return (1);
		x++;
	}
	return (0);
}

void	calc_x_y(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	i;

	x = 0;
	y = 0;
	i = 0;
	while (data->map != NULL && data->map[y] != NULL)
		y++;
	while ((data->map != NULL && data->map[i] != NULL))
	{
		if (x < ft_strlen(data->map[i]))
			x = ft_strlen(data->map[i]);
		i++;
	}
	data->rowsy = y;
	data->colsx = x;
}
