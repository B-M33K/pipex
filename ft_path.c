/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:39:58 by obahi             #+#    #+#             */
/*   Updated: 2023/01/21 11:14:39 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

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
