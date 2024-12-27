/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:15:26 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/27 14:44:55 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_elements(t_parser *parser, t_scene *scene)
{
	int	y;

	y = 0;
	while (parser->file[y] != NULL)
	{
		if (ft_strcmp(parser->file[y], "\n") == 0)
			y++;
		else
		{
			if (do_it(parser, parser->file[y]) == -1)
				return (-1);
			y++;
		}
	}
	if (parser->elem.qtt.no != 1 || parser->elem.qtt.so != 1 || \
	parser->elem.qtt.we != 1 || parser->elem.qtt.ea != 1 || \
	parser->elem.qtt.f != 1 || parser->elem.qtt.c != 1 || \
	parser->elem.qtt.is_zero != 0)
		return (1);
	if (check_f_c(parser, scene) == 1)
		return (1);
	return (0);
}

int	check_f_c(t_parser *parser, t_scene *scene)
{
	char	**sp_f;
	char	**sp_c;

	sp_f = ft_split(parser->elem.f, ',');
	sp_c = ft_split(parser->elem.c, ',');
	if (contar_comas(parser->elem.f) != 2 || contar_comas(parser->elem.c) != 2)
		return (ft_free_game(sp_f), ft_free_game(sp_c), 1);
	if (count_args(sp_f) != 3 || count_args(sp_c) != 3)
		return (free(sp_f), free(sp_c), 1);
	else
	{
		if (check_rgb_nums(sp_f) == 0 && check_rgb_nums(sp_c) == 0)
		{
			if (convert_hexa(sp_f, sp_c, scene) == 1)
				return (ft_free_game(sp_f), ft_free_game(sp_c), 1);
		}
		else
			return (ft_free_game(sp_f), ft_free_game(sp_c), 1);
	}
	ft_free_game(sp_f);
	ft_free_game(sp_c);
	return (0);
}

int	convert_hexa(char **sp_f, char **sp_c, t_scene *scene)
{
	int	r;
	int	g;
	int	b;

	r = atoi(sp_f[0]);
	g = atoi(sp_f[1]);
	b = atoi(sp_f[2]);
	scene->fcolor = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	r = atoi(sp_c[0]);
	g = atoi(sp_c[1]);
	b = atoi(sp_c[2]);
	scene->ccolor = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	return (0);
}

void	parser_init(t_parser *parser, char *str)
{
	parser->elem.qtt.no = 0;
	parser->elem.qtt.so = 0;
	parser->elem.qtt.we = 0;
	parser->elem.qtt.ea = 0;
	parser->elem.qtt.f = 0;
	parser->elem.qtt.c = 0;
	parser->elem.qtt.is_zero = 0;
	parser->elem.qtt.door = 0;
	parser->elem.no = NULL;
	parser->elem.so = NULL;
	parser->elem.we = NULL;
	parser->elem.ea = NULL;
	parser->elem.f = NULL;
	parser->elem.c = NULL;
	parser->rowsfile = 0;
	parser->colsx = 0;
	parser->rowsy = 0;
	parser->file = check_file(str);
}

int	check_rgb_nums(char **sp)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (sp[y] != NULL)
	{
		x = 0;
		while (sp[y][x] != '\0')
		{
			if (!ft_isdigit(sp[y][x]) && (sp[y][x] != '\0'
				&& sp[y][x] != '\n'))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
