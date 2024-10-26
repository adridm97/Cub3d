/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 12:02:48 by aduenas-          #+#    #+#             */
/*   Updated: 2023/05/20 12:26:54 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	size_t			i;

	if (s == NULL)
		return (0);
	if (start >= ft_strlen(s))
		return	(ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	dest = (char *)ft_calloc(len + 1, sizeof(char));
	if (dest == 0)
		return (0);
	i = 0;
	while (start < ft_strlen(s) && i < len && &s[start])
	{
		dest[i] = s[start];
		i++;
		start++;
	}
	return (dest);
}
