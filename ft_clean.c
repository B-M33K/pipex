/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:36:00 by obahi             #+#    #+#             */
/*   Updated: 2023/01/21 10:36:39 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

void	ft_clean(t_execve *exec1, t_execve *exec2)
{
	ft_free(exec1 -> args);
	free(exec1 -> cmd);
	free(exec1);
	ft_free(exec2 -> args);
	free(exec2 -> cmd);
	free(exec2);
}
