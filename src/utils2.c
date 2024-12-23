/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:15:26 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/23 19:55:52 by adrian           ###   ########.fr       */
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
	if (count_args(sp_f) != 3 || count_args(sp_c) != 3)
		return (free(sp_f), free(sp_c), 1);
	else
	{
		if (check_rgb_nums(sp_f) == 0 && check_rgb_nums(sp_c) == 0)
		{
			if (convert_hexa(sp_f, sp_c, scene) == 1)
				return (ft_free_game(sp_f), ft_free_game(sp_c), 0);
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
	int	num;
	int	num2;
	int	num3;

	num = 0;
	num2 = 0;
	num3 = 0;
	num = atoi(sp_f[0]);
	num2 = atoi(sp_f[1]);
	num3 = atoi(sp_f[2]);
	scene->fcolor = (num << 16) | (num2 << 8) | num3;
	num = atoi(sp_c[0]);
	num2 = atoi(sp_c[1]);
	num3 = atoi(sp_c[2]);
	scene->ccolor = (num << 16) | (num2 << 8) | num3;
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
	int	i;
	int	num;

	i = 0;
	while (sp[i] != NULL)
	{
		num = atoi(sp[i]);
		if (num >= 0 && num <= 255)
			return (0);
		i++;
	}
	return (1);
}

int	is_map_line(const char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '1' && *line != '0')
			return (0);
		line++;
	}
	return (1);
}

int	check_file1(const char *filename)
{
	int		fd;
	char	*line;
	char	*trimmed_line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (write(2, "Error opening file\n", 19), 1);
	line = get_next_line(fd);
	while (line)
	{
		trimmed_line = ft_strtrim(line, " \t\n");
		free(line);
		if (ft_strlen(trimmed_line) == 0)
		{
			free(trimmed_line);
			line = get_next_line(fd);
			continue ;
		}
		if (is_map_line(trimmed_line))
		{
			free(trimmed_line);
			close(fd);
			return (write(2, "Error: file starts with map\n", 28), 1);
		}
		free(trimmed_line);
		break ;
	}
	close(fd);
	return (0);
}

char	**check_file(char *str)
{
	char	**new;
	int		i;
	int		fd;

	fd = 0;
	i = -1;
	if (count_line(str) == 0)
		return (NULL);
	new = malloc(sizeof(char *) * (count_line(str) + 1));
	if (!new)
		return (NULL);
	if (!ft_contains_cub(str))
		return (write(2, "Invalid extention file\n", 22), free(new), NULL);
	if (check_file1(str) == 1)
		return (free(new), NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_free_game(new), ft_putstr_fd("error\n", 2), NULL);
	new[++i] = get_next_line(fd);
	while (new[i++] != NULL)
		new[i] = get_next_line(fd);
	close(fd);
	return (new);
}
