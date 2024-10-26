/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 18:22:15 by aduenas-          #+#    #+#             */
/*   Updated: 2023/05/06 20:56:58 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		*ptr1;
	size_t				i;

	i = 0;
	ptr = (unsigned char *)src;
	ptr1 = (unsigned char *)dst;
	while (dst == src || !n)
	{
		return (dst);
	}
	while (n > i)
	{
		ptr1[i] = ptr[i];
		i++;
	}
	return (dst);
}
