/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 00:02:48 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/06 18:27:41 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_vec2	scale_vec2(t_vec2 vec, double scale)
{
	vec.x *= scale;
	vec.y *= scale;
	return (vec);
}

t_vec2	create_vector2d(double x, double y)
{
	t_vec2	vec;

	vec.x = x;
	vec.y = y;
	return (vec);
}

double	length_vec2(t_vec2 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y));
}

void	set_player_dir(t_player *player, char c)
{
	if (c == 'N')
	{
		player->dir = create_vector2d(0, -1);
		player->plane = create_vector2d(0.66, 0);
	}
	else if (c == 'S')
	{
		player->dir = create_vector2d(0, 1);
		player->plane = create_vector2d(-0.66, 0);
	}
	else if (c == 'W')
	{
		player->dir = create_vector2d(-1, 0);
		player->plane = create_vector2d(0, -0.66);
	}
	else if (c == 'E')
	{
		player->dir = create_vector2d(1, 0);
		player->plane = create_vector2d(0, 0.66);
	}
}

t_player	set_player(char **map)
{
	int			i;
	int			j;
	t_player	player;

	ft_memset(&player, 0, sizeof(t_player));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]) != NULL)
			{
				player.pos = create_vector2d((double)j + 0.5, (double)i + 0.5);
				set_player_dir(&player, map[i][j]);
				player.dir_len = length_vec2(player.dir);
				player.plane = scale_vec2(player.plane, 1.5f);
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}
