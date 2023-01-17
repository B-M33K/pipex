/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:04:36 by obahi             #+#    #+#             */
/*   Updated: 2022/10/22 12:39:44 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*ret;
	int					size;
	int					i;

	if (!s)
		return (0);
	size = len + 1;
	i = 0;
	if (start + len > ft_strlen(s))
		size = ft_strlen(s) - start + 1;
	if (start >= ft_strlen(s))
		size = 1;
	ret = malloc(size);
	if (ret)
	{
		s += start;
		while (size - 1 > 0)
		{
			*(ret + i) = *(s + i);
			size --;
			i++;
		}
		*(ret + i) = '\0';
	}
	return (ret);
}
