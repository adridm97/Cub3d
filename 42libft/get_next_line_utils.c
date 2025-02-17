/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 20:36:45 by aduenas-          #+#    #+#             */
/*   Updated: 2024/12/03 17:39:26 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	char		*buffer;
	size_t		i;
	size_t		j;

	buffer = (char *)malloc(sizeof(*str1) \
				* (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		buffer[j++] = str1[i];
		i++;
	}
	i = 0;
	while (str2[i])
	{
		buffer[j++] = str2[i];
		i++;
	}
	buffer[j] = 0;
	return (buffer);
}

char	*ft_strchr_getline(const char *string, int c)
{
	char	*str;

	str = (char *)string;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

// size_t	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i])
// 		i++;
// 	return (i);
// }

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	char	*res;

// 	res = malloc(size * count);
// 	if (!res)
// 		return (NULL);
// 	ft_bzero(res, size * count);
// 	return (res);
// }
