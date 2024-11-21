/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:08:43 by adrian            #+#    #+#             */
/*   Updated: 2024/11/19 18:49:49 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define WIDTH 700
# define HEIGHT 700
#define TILE_SIZE 32

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "./42libft/get_next_line.h"
# include "./42libft/libft.h"
#include "./MLX42/include/MLX42/MLX42.h"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_mapData
{
	t_color	floor;
	t_color	ceiling;
	t_color	north_texture;
	t_color	south_texture;
	t_color	west_texture;
	t_color	east_texture;
	int		player_x;
	int		player_y;
	int		player_dir_x;
	int		player_dir_y;
	double	plane_x;
	double	plane_y;
	char	player_dir;
	char	**map;
	int		width;
	int		height;
}	t_mapData;

#endif