/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:36:12 by obahi             #+#    #+#             */
/*   Updated: 2023/01/19 12:56:12 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_perror(int n, const char *str)
{
	if (n == -1)
	{
		perror(str);
		exit(1);
	}
}

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
	int		i;

	if (!envp)
		return (0);
	i = 0;
	while (*(envp + i))
	{
		if (!ft_strncmp(*(envp + i), "PATH", 4))
		{
			paths = ft_strdup(*(envp + i) + 5);
			break ;
		}
		i++;
	}
	path = ft_split(paths, ':');
	free(paths);
	paths = 0;
	i = 0;
	while (*(path + i))
	{
		*(path + i) = ft_strjoin(*(path + i), "/");
		i++;
	}
	return (path);
}

char	*ft_cmd(char *cmd, char **path)
{
	char	*tmp;
	char	*cmmd;
	int		i;

	if (!path)
		return (0);
	i = 0;
	while (*(path + i))
	{
		tmp = ft_strjoin(*(path + i), cmd);
		if (!access(tmp, F_OK | X_OK))
		{
			cmmd = tmp;
			break ;
		}
		// free(tmp);
		i++;
	}
	return (cmmd);
}