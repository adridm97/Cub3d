/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:17:47 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/23 20:29:33 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_data(t_parser *parser, t_data *data, t_scene *scene)
{
	int	y;

	y = 0;
	while (data && data->map && data->map[y])
	{
		free(data->map[y]);
		y++;
	}
	free(data->map);
	free_scene(parser, scene);
}

void	ft_free_game(char **check_line)
{
	int	i;

	i = 0;
	while (check_line[i] != NULL)
	{
		free(check_line[i]);
		i++;
	}
	free(check_line);
}

void	free_string(char *str)
{
	if (str)
		free(str);
}

void	free_scene(t_parser *parser, t_scene *scene)
{
	free_mlx(scene, parser);
	free_parser(parser);
}

void	free_parser(t_parser *parser)
{
	int	y;

	y = 0;
	while (parser && parser->file && parser->file[y])
	{
		free(parser->file[y]);
		y++;
	}
	free(parser->file);
}
