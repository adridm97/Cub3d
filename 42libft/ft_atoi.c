/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduenas- <aduenas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 12:41:02 by aduenas-          #+#    #+#             */
/*   Updated: 2023/05/06 12:48:56 by aduenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	i;
	int			n;
	int			sign;

	sign = 1;
	n = 0;
	i = 0;
	while (str[n] == ' ' || (str[n] >= 9 && str[n] <= 13))
		n++;
	if (str[n] == '+' || str[n] == '-')
	{
		if (str[n] == '-')
		{
			sign = -1;
			n++;
		}
		else
			n++;
	}
	while (str[n] >= '0' && str[n] <= '9')
	{
		i = i * 10 + (str[n] - '0');
		n++;
	}
	return (i * sign);
}

/*int main(void)
{
    char str[] = "    -129a2";
    ft_atoi(str);
    return (0);
}*/
