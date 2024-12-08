/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 12:39:56 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/07 12:46:03 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void close_window(void *param)
{
    t_data *data = (t_data *)param;
    cleanup(data);
}

void cleanup(t_data *data)
{
    if (data->minimap.img)
        mlx_delete_image(data->scene->mlx, data->minimap.img);
    if (data->image)
        mlx_delete_image(data->scene->mlx, data->image);
    if (data->scene->mlx)
        mlx_terminate(data->scene->mlx);
    // free(data->scene);
    // free(data);
    exit(0);
}