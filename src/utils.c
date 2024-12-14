/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:17:09 by mel-atta          #+#    #+#             */
/*   Updated: 2024/12/14 21:00:02 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	count_args(char **check_line)
{
	int i;

	i = 0;
	while (check_line[i] != NULL)
		i++;
	return (i);
}

int	ft_contains_cub(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len < 4)
		return 0;
	return (ft_strcmp(str + len - 4, ".cub") == 0);
}

int	initialize_map(t_map *map)
{
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
	map->nexit = 0;
	map->ncoins = 0;
	return (1);
}

 void trim_first(char *s1, char *s2, int *start)
 {
     int i;
     int j;
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

int	count_line(char *str)
{
	char	*new;
	int		fd;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: No se pudo abrir el archivo.\n");
		return (0);
	}
	new = get_next_line(fd);
	while (new != NULL)
	{
		i++;
		free(new);
		new = get_next_line(fd);
	}
	free(new);
	close(fd);
	return (i);
}