/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:43:08 by obahi             #+#    #+#             */
/*   Updated: 2023/01/20 20:47:56 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*tmp2;

	if (!s1)
		s1 = ft_strdup("");
	join = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (join)
	{
		tmp2 = join;
		while (*s1)
			*tmp2++ = *s1++;
		while (*s2)
			*tmp2++ = *s2++;
		*tmp2 = '\0';
	}
	free(tmp2);
	return (join);
}
