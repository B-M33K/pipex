/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:06:46 by obahi             #+#    #+#             */
/*   Updated: 2023/01/19 12:53:50 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**path;
	char	**args;
	char	*cmd;
	int		t[2];
	int		infile;
	int		outfile;
	pid_t	pid;
	int		p;
	int		d;
	int		x;

	// ./pipex infile cmd1 cmd2 outfile
	// 		0	 1		2	 3	   4
	if (argc == 5)
	{
		path = ft_path(envp);
		infile = open(*(argv + 1), O_RDONLY);
		outfile = open(*(argv + 4), O_WRONLY | O_TRUNC | O_CREAT, 0777);
		p = dup2(infile, 0);
		ft_perror(p, "infile dup failed");
		// if (p == -1)
		// {
		// 	perror("infile dup failed : ");
		// 	exit(1);
		// }
		close(infile);
		p = dup2(outfile, 1);
		ft_perror(p, "outfile dup failed");
		// if (p == -1)
		// {
		// 	perror("outfile dup failed : ");
		// 	exit(1);
		// }
		close(outfile);
		p = pipe(t);
		ft_perror(p, "pipe failed");
		// if (p == -1)
		// {
		// 	perror("pipe failed : ");
		// 	exit(1);
		// }
		pid = fork();
		ft_perror(pid, "fork 1 failed");
		// if (pid == -1)
		// {
		// 	perror("fork 1 failed : ");
		// 	exit(1);
		// }
		if (!pid)
		{
			args = ft_split(*(argv + 2), ' ');
			cmd = ft_cmd(*args, path);
			close(t[0]);
			d = dup2(t[1], 1);
			ft_perror(d, "t[1] dup failed");
			// if (d == -1)
			// {
			// 	perror("t[1] dup failed : ");
			// 	exit(1);
			// }
			close(t[1]);
			x = execve(cmd, args, envp);
			ft_perror(x, "execve cmd1 failed");
			// if (x == -1)
			// {
			// 	perror("execve cmd1 failed : ");
			// 	exit(1);
			// }
		}
		pid = fork();
		ft_perror(pid, "fork 2 failed");
		// if (pid == -1)
		// {
		// 	perror("fork 2 failed : ");
		// 	exit(1);
		// }
		if (!pid)
		{
			args = ft_split(*(argv + 3), ' ');
			cmd = ft_cmd(*args, path);
			close(t[1]);
			d = dup2(t[0], 0);
			ft_perror(d, "t[0] dup failed");
			// if (d == -1)
			// {
			// 	perror("t[0] dup failed : ");
			// 	exit(0);
			// }
			close(t[0]);
			x = execve(cmd, args, envp);
			ft_perror(x, "execve cmd2 failed");
			// if (x == -1)
			// {
			// 	perror("execve cmd2 failed : ");
			// 	exit(1);
			// }
		}
		close(t[0]);
		close(t[1]);
		waitpid(-1, 0, 0);
		waitpid(-1, 0, 0);
		return (0);
	}
}