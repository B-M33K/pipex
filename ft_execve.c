/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:37:46 by obahi             #+#    #+#             */
/*   Updated: 2023/01/21 10:37:56 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_execve(t_execve *exec)
{
	int	x;

	ft_dup2(exec -> t1, exec -> i);
	close(exec -> t2);
	x = execve(exec -> cmd, exec -> args, exec -> envp);
	if (x == -1)
	{
		perror("execve failed");
		exit(1);
	}
}
