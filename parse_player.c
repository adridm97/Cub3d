/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:58:04 by adrian            #+#    #+#             */
/*   Updated: 2024/11/14 20:49:48 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	parse_player_position(t_mapData *map_data)
{
	int		x;
	int		y;
	int		found;
	char	cell;

	x = 0;
	found = 0;
    y = 0;
    while (y < map_data->height && !found)
	{
        x = 0;
        while (x < map_data->width && !found)
		{
            cell = map_data->map[y][x];
            if (cell == 'N' || cell == 'S' || cell == 'E' || cell == 'W')
			{
                map_data->player_x = x + 0.5;
                map_data->player_y = y + 0.5;
                found = 1;
                if (cell == 'N')
				{
                    map_data->player_dir_x = 0;
                    map_data->player_dir_y = -1;
                    map_data->plane_x = 0.66;
                    map_data->plane_y = 0;
                }
				else if (cell == 'S')
				{
                    map_data->player_dir_x = 0;
                    map_data->player_dir_y = 1;
                    map_data->plane_x = -0.66;
                    map_data->plane_y = 0;
                }
				else if (cell == 'E')
				{
                    map_data->player_dir_x = 1;
                    map_data->player_dir_y = 0;
                    map_data->plane_x = 0;
                    map_data->plane_y = 0.66;
                }
				else if (cell == 'W')
				{
                    map_data->player_dir_x = -1;
                    map_data->player_dir_y = 0;
                    map_data->plane_x = 0;
                    map_data->plane_y = -0.66;
                }
            }
            x++;
        }
        y++;
    }
    if (!found)
	{
        fprintf(stderr, "Error: No se encontró la posición inicial del jugador.\n");
        exit(1);
    }
}
