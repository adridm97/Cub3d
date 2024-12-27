/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:27:24 by adrian            #+#    #+#             */
/*   Updated: 2024/12/27 19:17:42 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_byte	key_pressed(t_key key)
{
	return (!key.prev && key.curr);
}

t_byte	key_released(t_key key)
{
	return (key.prev && !key.curr);
}

t_byte	key_held(t_key key)
{
	return (key.prev && key.curr);
}

void	update_keys(t_keys *keys, void *mlx)
{
	keys->esc.prev = keys->esc.curr;
	keys->esc.curr = mlx_is_key_down(mlx, MLX_KEY_ESCAPE);
	keys->w.prev = keys->w.curr;
	keys->w.curr = mlx_is_key_down(mlx, MLX_KEY_W);
	keys->a.prev = keys->a.curr;
	keys->a.curr = mlx_is_key_down(mlx, MLX_KEY_A);
	keys->s.prev = keys->s.curr;
	keys->s.curr = mlx_is_key_down(mlx, MLX_KEY_S);
	keys->d.prev = keys->d.curr;
	keys->d.curr = mlx_is_key_down(mlx, MLX_KEY_D);
	keys->left.prev = keys->left.curr;
	keys->left.curr = mlx_is_key_down(mlx, MLX_KEY_LEFT);
	keys->right.prev = keys->right.curr;
	keys->right.curr = mlx_is_key_down(mlx, MLX_KEY_RIGHT);
}
