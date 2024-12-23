/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:17:09 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/23 20:32:46 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_args(char **check_line)
{
	int	i;

	i = 0;
	while (check_line[i] != NULL)
		i++;
	return (i);
}

int	ft_contains_cub(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	return (ft_strcmp(str + len - 4, ".cub") == 0);
}

int	initialize_map(t_map *map)
{
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	map->nexit = 0;
	map->ncoins = 0;
	return (1);
}

int	count_line(char *str)
{
	char	*new;
	int		fd;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: No se pudo abrir el archivo.\n");
		return (0);
	}
	new = get_next_line(fd);
	while (new != NULL)
	{
		i++;
		free(new);
		new = get_next_line(fd);
	}
	free(new);
	close(fd);
	return (i);
}
