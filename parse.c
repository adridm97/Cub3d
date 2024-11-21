/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:03:21 by adrian            #+#    #+#             */
/*   Updated: 2024/11/19 18:29:15 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	isValidMap(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' ' &&
			line[i] != 'N' && line[i] != 'S' && line[i] != 'E' && line[i] != 'W' && line[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}

void	parse_color(char *line, t_color *color)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == 'F' || line[i] == 'C' || line[i] == ' '))
		i++;
	color->r = ft_atoi(&line[i]);
	while (line[i] && line[i] != ',')
		i++;
	color->g = ft_atoi(&line[++i]);
	while (line[i] && line[i] != ',')
		i++;
	color->b = ft_atoi(&line[++i]);
}

void	parse_texture_path(char *line, char **texture_path)
{
    int	i;
	
	i = 0;
    if (ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0 ||
        ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA", 2) == 0)
        i += 2;
    while (line[i] == ' ')
        i++;
    *texture_path = ft_strdup(&line[i]);
}

void	parse_file(int fd, t_mapData *map_data, char *filename)
{
	char	*line;
	int		y;
	int		max_width;
	int		width;
	int		i;
	int		x;

	line = get_next_line(fd);
	y = 0;
	max_width = 0;
	map_data->north_texture = (t_color){0, 0, 0};
	map_data->south_texture = (t_color){128, 128, 128};
	map_data->east_texture = (t_color){0, 0, 255};
	map_data->west_texture = (t_color){0, 255, 0};
	while (line != NULL)
	{
		if (line[0] == 'F')
			parse_color(line, &map_data->floor);
		else if (line[0] == 'C')
			parse_color(line, &map_data->ceiling);
		// else if (ft_strncmp(line, "NO", 2) == 0)
		// 	parse_texture_path(line, &map_data->north_texture);
		// else if (ft_strncmp(line, "SO", 2) == 0)
		// 	parse_texture_path(line, &map_data->south_texture);
		// else if (ft_strncmp(line, "WE", 2) == 0)
		// 	parse_texture_path(line, &map_data->west_texture);
		// else if (ft_strncmp(line, "EA", 2) == 0)
		// 	parse_texture_path(line, &map_data->east_texture);
		else if (isValidMap(line) == 0)
		{
			map_data->height++;
			width = ft_strlen(line);
			if (width > max_width)
				max_width = width;
		}

		free(line);
		line = get_next_line(fd);
	}
	map_data->width = max_width;
	map_data->map = (char **)malloc(sizeof(char *) * map_data->height);
	i = 0;
	while (i < map_data->height)
	{
		map_data->map[i] = (char *)malloc(sizeof(char) * (map_data->width + 1));
		i++;
	}
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error al abrir el archivo");
		return;
	}
	line = get_next_line(fd);
	y = 0;
	while (line != NULL)
	{
		if (isValidMap(line) == 0)
		{
			x = 0;
			while (x < map_data->width && line[x] != '\n')
			{
				map_data->map[y][x] = line[x];
				if (line[x] == 'N' || line[x] == 'S' || line[x] == 'E' || line[x] == 'W')
				{
					map_data->player_x = x;
					map_data->player_y = y;
					map_data->player_dir = line[x];
				}
				x++;
			}
			y++;
		}
		free(line);
		line = get_next_line(fd);
	}
	map_data->map[y] = NULL;
	close(fd);
}
