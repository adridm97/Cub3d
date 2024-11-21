/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:04:15 by adrian            #+#    #+#             */
/*   Updated: 2024/11/19 22:45:24 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"


//parse.c
void    parse_file(int fd, t_mapData *mapData, char *filename);
void	parse_color(char *line, t_color *color);
void	parse_texture_path(char *line, char **texture_path);
int     isValidMap(char *line);

//minimap.c
void	draw_minimap(mlx_t *mlx, t_mapData *map_data);

//key_events.c
void key_hook(mlx_key_data_t keydata, void *param);

//parse_player.c
void	parse_player_position(t_mapData *map_data);

//ray_casting.c
void	draw_walls(void *mlx, mlx_image_t *image, t_mapData *map_data);
#endif