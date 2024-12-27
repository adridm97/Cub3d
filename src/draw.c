/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 12:59:00 by adrian            #+#    #+#             */
/*   Updated: 2024/12/26 13:31:31 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/cub3d.h"

void	draw_wall_column_optimized(t_data *data, t_wall *walls, mlx_image_t *texture, int x)
{
    uint32_t    *pixels;
    uint32_t    *tex_pixels;
    int         y;

    pixels = (uint32_t *)data->image->pixels;
    tex_pixels = (uint32_t *)texture->pixels;
    y = walls->draw_start;
    while (y < walls->draw_end)
    {
        walls->tex_y = (int)walls->tex_pos & (texture->height - 1);
        walls->tex_pos += walls->step;
        walls->color = tex_pixels[walls->tex_y * texture->width + walls->tex_x];
        pixels[y * WIDTH + x] = walls->color;
        y++;
    }
}