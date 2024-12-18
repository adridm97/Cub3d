/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_colision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 12:35:00 by adrian            #+#    #+#             */
/*   Updated: 2024/12/16 18:57:05 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

bool	is_wall(t_data *data, float x, float y)
{
    int map_x;
	int	map_y;
	int	block_size;

	block_size = WIDTH / data->colsx;
	printf("Tamaño del mapa: %d , %d \n", data->colsx, data->rowsy);
    map_x = (int)(x / block_size);
    map_y = (int)(y / block_size);
	printf("Coordenadas transformadas a índices (map_x: %d, map_y: %d) desde (x: %f, y: %f)\n", map_x, map_y, x, y);
	if (map_x < 0 || map_y < 0 || map_y >= data->rowsy || map_x >= data->colsx)
	{
		printf("Índices fuera de los límites del mapa en is_wall (map_x: %d, map_y: %d)\n", map_x, map_y);
		return (true);
	}
	printf("Celda en mapa[%d][%d]: %c\n", map_y, map_x, data->map[map_y][map_x]);
    if (data->map[map_y][map_x] == '1')
	{
		printf("Muro detectado en (x: %f, y: %f)\n", x, y);
		return (true);
	}
	return (false);
}

bool	check_collision(t_data *data, t_vec2 new_pos)
{
	float	radius;

	radius = 5.0f;
	
	if (new_pos.x < 0 || new_pos.y < 0 || new_pos.y >= HEIGHT || new_pos.x >= WIDTH)
    {
        printf("Fuera de límites del mapa.\n");
        return true;
    }
	if (is_wall(data, new_pos.x - radius, new_pos.y - radius) || 
		is_wall(data, new_pos.x + radius, new_pos.y - radius) || 
		is_wall(data, new_pos.x - radius, new_pos.y + radius) || 
		is_wall(data, new_pos.x + radius, new_pos.y + radius))
	{
		printf("Colisión detectada en esa posición\n");
		return (true);
	}
	printf("No hay colisión en esa posición\n");
	return (false);
}