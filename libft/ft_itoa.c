/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:31:00 by obahi             #+#    #+#             */
/*   Updated: 2022/10/19 20:32:03 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_nbrlen(int n)
{
	int				len;
	unsigned int	nbr;

	len = 1;
	nbr = n;
	if (n < 0)
	{
		len++;
		nbr = -n;
	}
	while (nbr / 10)
	{
		len ++;
		nbr /= 10;
	}
	return (len);
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (*(str + j))
		j++;
	j--;
	while (i < j)
	{
		tmp = *(str + i);
		*(str + i) = *(str + j);
		*(str + j) = tmp;
		i++;
		j--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	unsigned int	un;
	int				size;
	char			*arg;
	char			*itr;

	un = n;
	size = ft_nbrlen(n);
	if (n < 0)
		un = -n;
	arg = malloc(size + 1);
	if (!arg)
		return (0);
	itr = arg;
	while (un / 10 > 0)
	{
		*itr++ = un % 10 + 48;
		un /= 10;
	}
	*itr++ = un % 10 + 48;
	if (n < 0)
		*itr++ = '-';
	*itr = '\0';
	return (ft_strrev(arg));
}
