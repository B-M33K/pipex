/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:39:03 by obahi             #+#    #+#             */
/*   Updated: 2023/01/21 10:39:22 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

t_execve	*ft_initialize(char **envp, char *argv, int t[2], int i)
{
	t_execve	*exe;
	char		**path;

	exe = malloc(sizeof(t_execve));
	if (!exe)
		return (0);
	path = ft_path(envp);
	exe -> envp = envp;
	exe -> args = ft_split(argv, ' ');
	exe -> cmd = ft_cmd(*(exe -> args), path);
	exe -> t1 = t[i];
	exe -> i = i;
	exe -> t2 = t[(i + 1) % 2];
	ft_free(path);
	return (exe);
}
