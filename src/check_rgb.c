/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moha <moha@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 14:32:38 by moha              #+#    #+#             */
/*   Updated: 2024/12/25 15:07:16 by moha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	contar_comas(const char *cadena)
{
	int	contador;

	contador = 0;

	while (*cadena != '\0')
	{
		if (*cadena == ',')
		{
			contador++;
		}
		cadena++;
	}

	return (contador);
}

int	check_rgb_rang(int r, int g, int b)
{
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
		return (0);
	return (1);
}
