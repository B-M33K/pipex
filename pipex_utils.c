/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:36:12 by obahi             #+#    #+#             */
/*   Updated: 2023/01/20 21:04:27 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (*(ptr + i))
	{
		free(*(ptr + i));
		i++;
	}
	free(ptr);
}

char	**ft_path(char **envp)
{
	char	*paths;
	char	**path;
	char	*tmp;
	int		i;

	if (!envp)
		return (0);
	paths = 0;
	i = -1;
	while (*(envp + (++i)) && !paths)
	{
		if (!ft_strncmp(*(envp + i), "PATH", 4))
			paths = ft_strdup(*(envp + i) + 5);
	}
	path = ft_split(paths, ':');
	free(paths);
	i = -1;
	while (*(path + (++i)))
	{
		tmp = *(path + i);
		*(path + i) = ft_strjoin(*(path + i), "/");
		free(tmp);
	}
	return (path);
}

char	*ft_cmd(char *cmd, char **path)
{
	char	*tmp;
	int		i;

	if (!path)
		return (0);
	i = 0;
	while (*(path + i))
	{
		tmp = ft_strjoin(*(path + i), cmd);
		if (!access(tmp, F_OK | X_OK))
			return (tmp);
		free(tmp);
		i++;
	}
	return (0);
}

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

void	ft_clean(t_execve *exec1, t_execve *exec2)
{
	ft_free(exec1 -> args);
	free(exec1 -> cmd);
	free(exec1);
	ft_free(exec2 -> args);
	free(exec2 -> cmd);
	free(exec2);
}
