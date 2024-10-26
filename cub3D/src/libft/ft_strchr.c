/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 22:10:15 by mel-atta          #+#    #+#             */
/*   Updated: 2024/10/26 18:05:07 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *str, int c)
{
	//int	i;

	//i = 0;
	if (str == NULL)
		return (NULL);
	return (ft_memchr(str, c, ft_strlen(str) + 1));
}
/*int	main(void)
{
	char str[100] = "teste";
	int c = 1024;
	printf("custom: %s\n", ft_strchr(str, c));
	printf("original: %s\n", strchr(str, c));
}*/
