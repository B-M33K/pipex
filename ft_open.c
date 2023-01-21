/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:39:28 by obahi             #+#    #+#             */
/*   Updated: 2023/01/21 10:39:50 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_open(int *fd, char *path, int oflag, mode_t mode)
{
	*fd = open(path, oflag, mode);
	if (*fd == -1)
	{
		perror("open file failed");
		exit(1);
	}
}
