/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:36:53 by obahi             #+#    #+#             */
/*   Updated: 2023/01/21 10:37:12 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

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
