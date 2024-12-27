/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:22:56 by aduenas-          #+#    #+#             */
/*   Updated: 2024/12/27 19:24:13 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_scene_map(char **map, int rows)
{
	int	i;

	if (map == NULL)
		return ;
	i = 0;
	while (i < rows)
	{
		if (map[i] != NULL)
			free(map[i]);
		i++;
	}
	free(map);
}

char	**padding_map(char **map, int *rows, int *cols)
{
	char	**new_map;
	int		i;

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
			return (free_map(new_map, i), NULL);
		ft_memset(new_map[i], ' ', *cols + 1);
		if (i >= 10 && i < *rows - 10)
		{
			ft_strlcpy(new_map[i] + 10 - 2, map[i - 10], *cols + 1);
		}
		new_map[i][*cols] = '\0';
		i++;
	}
	new_map[i] = NULL;
	free_map(map, *rows -20);
	return (new_map);
}
