/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moha <moha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 00:26:15 by moha              #+#    #+#             */
/*   Updated: 2024/12/24 00:40:43 by moha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error opening file\n", 19);
	}
	return (fd);
}

int	process_line(char *line, int fd)
{
	char	*trimmed_line;

	(void)fd;
	trimmed_line = ft_strtrim(line, " \t\n");
	free(line);
	if (ft_strlen(trimmed_line) == 0)
	{
		free(trimmed_line);
		return (1);
	}
	free(trimmed_line);
	return (0);
}

int	check_file1(const char *filename)
{
	char	*line;
	int		fd;

	fd = open_file(filename);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (process_line(line, fd))
		{
			line = get_next_line(fd);
			continue ;
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
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
