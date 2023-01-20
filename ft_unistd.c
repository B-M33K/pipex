/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unistd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:27:46 by obahi             #+#    #+#             */
/*   Updated: 2023/01/20 20:53:23 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_dup2(int i, int j)
{
	int	error;

	error = dup2(i, j);
	if (error == -1)
	{
		perror("dup failed");
		exit(1);
	}
	close(i);
}

void	ft_pipe(int t[2])
{
	int	error;

	error = pipe(t);
	if (error == -1)
	{
		perror("pipe failed");
		exit(1);
	}
}

void	ft_open(int *fd, char *path, int oflag, mode_t mode)
{
	*fd = open(path, oflag, mode);
	if (*fd == -1)
	{
		perror("open file failed");
		exit(1);
	}
}

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

void	ft_fork(t_execve *exe)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	if (!pid)
		ft_execve(exe);
}
