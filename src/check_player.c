/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:17:39 by mel-atta          #+#    #+#             */
/*   Updated: 2024/11/23 12:17:43 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_player(char **map, t_parser *parser)
{
	int		count;
	t_point	pos;

	count = 0;
	pos = init_pos();
	while (map != NULL && map[pos.y] != NULL)
	{
		if (map[pos.y][++pos.x] == '\0')
		{
			pos.x = -1;
			pos.y++;
		}
		else
		{
			if (is_player(map, pos.x, pos.y))
			{
				parser->letter_player = map[pos.y][pos.x];
				count++;
			}
		}
	}
	if (count != 1)
		return (1);
	return (0);
}

int	check_space(char **map, int x, int y, char letter_player)
{
	if (map[y][x] != '1' && map[y][x] != '0' && map[y][x] != ' '
		&& map[y][x] != letter_player && map[y][x] != '\0' && map[y][x] != '\n')
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letter_player) && y == 0)
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letter_player) && (map[y
			- 1][x] == ' ' || map[y + 1][x] == ' '))
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letter_player) && map[y + 1] == NULL)
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letter_player) && (map[y][x
			+ 1] == ' ' || map[y][x + 1] == '\0'))
		return (1);
	if ((map[y][x] == '0' || map[y][x] == letter_player) && map[y][x
		- 1] == ' ')
		return (1);
	return (0);
}

t_point	init_pos(void)
{
	t_point	pos;

	pos.x = -1;
	pos.y = 0;
	return (pos);
}

int	is_player(char **map, int x, int y)
{
	if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'W'
		|| map[y][x] == 'E')
		return (1);
	return (0);
}

int	ft_rowsfile(char **file)
{
	int	i;

	i = 0;
	while (file[i] != NULL)
		i++;
	return (i);
}