/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:31:28 by obahi             #+#    #+#             */
/*   Updated: 2022/10/19 11:23:06 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_charinset(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_size(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	while (ft_charinset(*(s1 + start), set))
		start++;
	if (start == end)
		return (0);
	while (ft_charinset(*(s1 + end - 1), set))
		end--;
	return (end - start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		size;
	int		i;

	if (!s1)
		return (0);
	start = 0;
	while (ft_charinset(*(s1 + start), set))
		start++;
	size = ft_size(s1, set);
	ptr = malloc(size + 1);
	i = 0;
	if (ptr)
	{
		while (i < size)
		{
			*(ptr + i) = *(s1 + start + i);
			i++;
		}
		*(ptr + i) = 0;
	}
	return (ptr);
}
