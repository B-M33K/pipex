#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	// ./pipex infile cmd outfile
	//    0      1     2	3
	char	**path;
	char	**args;
	char	*cmd;
	int		infile;
	int		outfile;
	pid_t	pid;
	int		d;
	int		x;

	if (argc == 4)
	{
		infile = open(*(argv + 1), O_RDONLY);
		outfile = open(*(argv + 3), O_WRONLY | O_TRUNC | O_CREAT, 0777);
		d = dup2(infile, 0);
		if (d == -1)
		{
			perror("infile dup failed : ");
			exit(1);
		}
		close(infile);
		d = dup2(outfile, 1);
		if (d == -1)
		{
			perror("outfile dup failed : ");
			exit(1);
		}
		close(outfile);
		path = ft_path(envp);
		pid = fork();
		if (pid == -1)
		{
			perror("fork failed : ");
			exit(0);
		}
		if (!pid)
		{
			args = ft_split(*(argv + 2), ' ');
			cmd = ft_cmd(*args, path);
			x = execve(cmd, args, envp);
			if (x == -1)
			{
				perror("execve failed : ");
				exit(0);
			}
		}
		waitpid(-1, 0, 0);
		return (0);
	}
}