/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:06:46 by obahi             #+#    #+#             */
/*   Updated: 2023/01/21 13:27:43 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_execve	*exec1;
	t_execve	*exec2;
	int			t[2];
	int			infile;
	int			outfile;

	if (argc == 5)
	{
		ft_open(&infile, *(argv + 1), O_RDONLY, 0);
		ft_open(&outfile, *(argv + 4), O_WRONLY | O_TRUNC | O_CREAT, 0777);
		ft_dup2(infile, 0);
		ft_dup2(outfile, 1);
		ft_pipe(t);
		exec1 = ft_initialize(envp, *(argv + 2), t, 1);
		exec2 = ft_initialize(envp, *(argv + 3), t, 0);
		ft_fork(exec1);
		ft_fork(exec2);
		ft_close(t);
		waitpid(-1, 0, 0);
		waitpid(-1, 0, 0);
		ft_clean(exec1, exec2);
	}
	return (0);
}
