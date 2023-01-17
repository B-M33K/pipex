/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:34:48 by obahi             #+#    #+#             */
/*   Updated: 2022/10/09 18:38:08 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = 0;
	dup = (char *)malloc(ft_strlen(src) + 1);
	if (dup)
	{
		while (*(src + i))
		{
			*(dup + i) = *(src + i);
			i++;
		}
		*(dup + i) = '\0';
	}
	return (dup);
}
