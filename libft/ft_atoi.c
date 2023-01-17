/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:40:36 by obahi             #+#    #+#             */
/*   Updated: 2022/10/22 08:12:40 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_overlongmin(const char *str)
{
	if (ft_strncmp(str, "-9223372036854775808", 20) >= 0)
		return (1);
	return (0);
}

static int	ft_overlongmax(const char *str)
{
	if (ft_strncmp(str, "9223372036854775807", 19) >= 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	n;

	sign = 1;
	n = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-' )
		{
			sign = -1;
			if (ft_strlen(str) >= 20 && ft_overlongmin(str))
				return (0);
		}
		str++;
	}
	if (ft_strlen(str) >= 19 && ft_overlongmax(str) && sign == 1)
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (sign * n);
}
