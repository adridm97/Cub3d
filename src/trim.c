/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrian <adrian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:31:57 by adrian            #+#    #+#             */
/*   Updated: 2024/12/23 20:32:53 by adrian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	trim_first(char *s1, char *s2, int *start)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				break ;
			j++;
		}
		if (s2[j] == '\0')
			break ;
		i++;
	}
	*start = i;
}

void	trim_last(char *s1, char *s2, int *end)
{
	int	i;
	int	j;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		j = 0;
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
				break ;
			j++;
		}
		if (s2[j] == '\0')
			break ;
		i--;
	}
	*end = i;
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*new;
	int		start;
	int		end;
	int		len;
	int		i;

	if (!s1)
		return (NULL);
	if (!s2)
		return (ft_strdup(""));
	i = 0;
	trim_first((char *)s1, (char *)s2, &start);
	trim_last((char *)s1, (char *)s2, &end);
	if (start > end)
		return (ft_strdup(""));
	len = end - start;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (start < end)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}
