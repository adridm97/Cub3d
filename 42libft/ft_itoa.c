/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:44:13 by aduenas-          #+#    #+#             */
/*   Updated: 2024/12/24 15:42:24 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count(long int n)
{
	size_t	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		size++;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

void	ft_base_converter(long int n, char *str, long int i)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	if (n >= 10)
		ft_base_converter((n / 10), str, (i - 1));
	str[i] = (n % 10) + '0';
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;

	size = ft_count(n);
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	str[size--] = '\0';
	ft_base_converter(n, str, size);
	return (str);
}
