/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:18:28 by aduenas-          #+#    #+#             */
/*   Updated: 2024/12/21 15:35:15 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_textures(t_data *data)
{
	int	i;

	if (!data || !data->scene || !data->scene->textures)
		return ;
	i = 0;
	while (i < 4)
	{
		if (data->scene->textures[i])
		{
			free(data->scene->textures[i]);
			data->scene->textures[i] = NULL;
		}
		i++;
	}
	free(data->scene->textures);
	data->scene->textures = NULL;
}
