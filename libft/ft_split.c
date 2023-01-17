/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:20:59 by obahi             #+#    #+#             */
/*   Updated: 2022/10/23 09:12:13 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdio.h>

static int	ft_word_count(const char *s, char c)
{
	int	wc;
	int	i;

	wc = 0;
	i = 0;
	if (s)
	{
		if (*(s + i) && *(s + i) != c)
			wc++;
		while (*(s + i))
		{
			if (*(s + i) == c && *(s + i + 1) != c && *(s + i + 1))
				wc++;
			i++;
		}
	}
	return (wc);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;
	int		k;
	int		wc;

	i = 0;
	k = 0;
	wc = ft_word_count(s, c);
	split = malloc((wc + 1) * sizeof(char *));
	if (!split)
		return (0);
	while (k < wc)
	{
		while (*(s + i) && *(s + i) == c)
			i++;
		j = i;
		while (*(s + j) && *(s + j) != c)
			j++;
		*(split + k) = ft_substr(s, i, j - i);
		i = j;
		k++;
	}
	*(split + k) = 0;
	return (split);
}
