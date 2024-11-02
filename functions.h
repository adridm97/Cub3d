/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:04:15 by adrian            #+#    #+#             */
/*   Updated: 2024/10/30 20:44:38 by adrian           ###   ########.fr       */
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

#endif