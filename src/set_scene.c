/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:15:17 by mel-atta          #+#    #+#             */
/*   Updated: 2024/11/30 16:16:45 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void set_mlx(t_scene *scene, t_parser parser, t_data *data)
{

    scene->mlx = mlx_init(WIDTH, HEIGHT, "Cub3d", 1);
    if (scene->mlx == NULL)
    {
        free_data(&parser, data, scene);
        exit(0);
    }
    data->image = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
    if (data->image == NULL)
    {
        free_data(&parser, data, scene);
        exit(0);
    }
    // scene->win = mlx_new_window(scene->mlx, scene->width, scene->height, "Cub3D");
    // if (scene->win == NULL)
    // {
    //     free_data(&parser, &data, scene);
    //     exit(0);
    // }
}
void print_map(char **map, int rows) {
    for (int i = 0; i < rows; i++) {
        printf("%s\n", map[i]);
    }
}

void set_scene(t_scene *scene, t_parser parser, t_data *data)
 {
    calc_x_y(data);
    scene->rows = data->rowsy;
    scene->cols = data->colsx;

    // cubrir el mapa para protegerlo para el raycasting
    scene->map = padding_map(data->map, &scene->rows, &scene->cols);
    // printf("rows,%d cols %d\n", scene->rows, scene->cols);
    // print_map(scene->map, 32);
	// print_scene_map(scene->map, 29);
    scene->player = set_player(scene->map);
    set_mlx(scene, parser, data);
    if (scene->map == NULL)
    {
        free_data(&parser, data, scene);
        // mlx_destroy_window(scene->mlx, scene->win);
        exit(0);
    }
    // set_scene_image(scene, parser, *data);
}

char **padding_map(char **map, int *rows, int *cols)
{
    char    **new_map;
    int     i;

    delete_enter(map);
    *rows += 20 * 2;
    *cols += 20 * 2;
    new_map = malloc(sizeof(char *) * (*rows + 1));
    if (!new_map)
        return (NULL);
    i = 0;
    while (i < *rows)
    {
        new_map[i] = malloc(sizeof(char) * (*cols + 1));
        if (!new_map[i])
            return (ft_free_game(new_map), NULL);
        ft_memset(new_map[i], ' ', *cols + 1);
        if (i >= 20 && i < *rows - 20)
            ft_strlcpy(new_map[i] + 20 - 2, map[i - 20], *cols + 1);
        new_map[i][*cols] = '\0';
        i++;
    }
    new_map[i] = NULL;
    return (new_map);
}
