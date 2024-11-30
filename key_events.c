/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:57:16 by adrian            #+#    #+#             */
/*   Updated: 2024/11/30 16:31:12 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void key_hook()
{
	mlx_key_data_t keydata;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			printf("ESC pressed, exiting...\n");
			exit(0);
		}
		if (keydata.key == MLX_KEY_W)
			printf("W pressed\n");
		if (keydata.key == MLX_KEY_S)
			printf("S pressed\n");
		if (keydata.key == MLX_KEY_A)
			printf("A pressed\n");
		if (keydata.key == MLX_KEY_D)
			printf("D pressed\n");
		if (keydata.key == MLX_KEY_LEFT)
			printf("Left arrow pressed\n");
		if (keydata.key == MLX_KEY_RIGHT)
			printf("Right arrow pressed\n");
	}
}