/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:58:32 by obahi             #+#    #+#             */
/*   Updated: 2022/10/22 09:30:13 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*pdst;
	char			*psrc;
	unsigned int	i;

	pdst = (char *)dst;
	psrc = (char *)src;
	i = 0;
	if (!dst && !src)
		return (0);
	if (psrc >= pdst)
	{
		while (i < len)
		{
			*(pdst + i) = *(psrc + i);
			i++;
		}
	}
	else
	{
		while (len--)
		{
			*(pdst + len) = *(psrc + len);
		}
	}
	return (dst);
}
