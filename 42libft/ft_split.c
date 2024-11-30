/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-atta <mel-atta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 22:21:40 by aduenas-          #+#    #+#             */
/*   Updated: 2024/11/23 15:50:00 by mel-atta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int ft_count_c(char const *s, char c)
{
	int	i;
	int n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			n++;
		i++;
	}
	return (n);
}
char	**ft_free_split(char **split, size_t i)
{
	while (i > 0)
	{
		--i;
		free(split[i]);
	}
	free(split);
	return (NULL);
}
char	*ft_word(const char *s, int start, int end)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (word == NULL)
		return (NULL);
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}
char **ft_write(char **split, char const *s, char c)
{
	size_t i;
	size_t j;
	int	copy;

	i = 0;
	j = 0;
	copy = -1;
	while ( i <= ft_strlen(s))
	{
		if (s[i] != c && copy < 0)
			copy = i;
		else if ((s[i] == c || i == ft_strlen(s)) && copy >= 0)
		{
			split[j] = ft_word(s, copy, i);
			if(split[j] == NULL)
				return(ft_free_split(split, j));
			copy = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return(split);
}

char	**ft_split(char const *s, char c)
{
	char **split;

	if (!s)
		return (NULL);
	split = malloc((ft_count_c(s, c) + 1) * sizeof(char *));
	if (split == NULL)
		return(NULL);
	if(ft_write(split, s, c) == NULL)
		return(NULL);

	return (split);
}
/*int	main(void)
{
    const char *sentence = "Hola, esto,e s,una,cadena,separada,por,comas";
    char **words = ft_split(sentence, ' ');

    if (words != NULL)
    {
        int i = 0;
        while (words[i] != NULL)
        {
            printf("%s\n", words[i]);
            free(words[i]);
            i++;
        }
        free(words);
    }

    return 0;
}*/
