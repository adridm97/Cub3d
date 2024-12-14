/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 23:34:14 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/15 00:46:08 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include <stdlib.h>
#include <string.h>

int	main(int argc, char *argv[])
{
	t_data		data;
	t_parser	parser;
	t_scene		scene;

	if (argc != 2)
		return (write(2, "Bad arguments\n", 14), 2);
	parser_init(&parser, argv[1]);
	if (parser.file == NULL)
		return (free_parser(&parser), 1);
	if (check_elements(&parser, &scene))
		return (write(2, "Error file\n", 11), free_scene(&parser, &scene), 1);
	if (init_map(&data, &parser))
		return (write(2, "Error map\n", 10), free_data(&parser, &data, &scene),
			1);
	set_scene(&scene, parser, &data);
	if (check_map(&parser, scene))
	{
		write(2, "Error map\n", 10);
		free_data(&parser, &data, &scene);
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
