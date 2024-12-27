/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:34:14 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/26 18:18:36 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include <stdlib.h>
#include <string.h>

void	handle_args(int argc)
{
	if (argc != 2)
	{
		perror("Bad arguments\n");
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
		perror("Error File\n");
		free_scene(parser, scene);
		exit(1);
	}
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
		return (write(2, "Error map\n", 10), 1);
	}
	set_scene(&scene, parser, &data);
	if (check_map(&parser, scene))
	{
		write(2, "Error map\n", 10);
		free_data(&parser, &data, &scene);
		exit(1);
	}
	data.scene = &scene;
	data.parser = &parser;
	init_textures(&data);
	init_minimap(&data);
	mlx_loop_hook(scene.mlx, &render, &data);
	mlx_cursor_hook(scene.mlx, handle_mouse_move, &data);
	mlx_close_hook(scene.mlx, close_window, &data);
	mlx_loop(scene.mlx);
	mlx_terminate(scene.mlx);
}
