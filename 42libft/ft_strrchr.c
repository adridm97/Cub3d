/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:46:58 by aduenas-          #+#    #+#             */
/*   Updated: 2023/05/15 22:03:35 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*s_copy;
	int				i;
	unsigned char	val;

	s_copy = (char *) s;
	i = ft_strlen(s);
	val = (unsigned char) c;
	while (i >= 0)
	{
		if (s_copy[i] == val)
			return (&s_copy[i]);
		i--;
	}
	return (0);
}
