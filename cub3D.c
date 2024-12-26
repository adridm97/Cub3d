/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:34:14 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/26 22:06:07 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include <stdlib.h>
#include <string.h>

void	handle_args(int argc)
{
	if (argc != 2)
	{
		write(2, "Bad arguments\n", 14);
		exit(1);
	}
}

void	init_parser(t_parser *parser, t_scene *scene, char *file)
{
	parser_init(parser, file);
	if (parser->file == NULL)
	{
		free_parser(parser);
		exit(1);
	}
	if (check_elements(parser, scene))
	{
		write(2, "Error File\n", 11);
		free_scene(parser, scene);
		exit(1);
	}
}

void	print_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
		printf("%s", map[i++]);
}
int	main(int argc, char *argv[])
{
	t_data		data;
	t_parser	parser;
	t_scene		scene;

	handle_args(argc);
	init_parser(&parser, &scene, argv[1]);
	if (init_map(&data, &parser))
	{
		free_data(&parser, &data, &scene);
		return (write(2, "Error map\n", 9), 1);
	}
	set_scene(&scene, parser, &data);
	if (check_map(&parser, scene))
	{
		write(2, "Error map\n", 9);
		free_data(&parser, &data, &scene);
		ft_free_game(scene.map);
		// print_map(scene.map, scene.rows);
		exit(1);
	}
	data.scene = &scene;
	data.parser = &parser;
	mlx_loop_hook(scene.mlx, &render, &data);
	mlx_cursor_hook(scene.mlx, handle_mouse_move, &data);
	mlx_close_hook(scene.mlx, close_window, &data);
	mlx_loop(scene.mlx);
	mlx_terminate(scene.mlx);
}
