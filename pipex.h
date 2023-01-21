/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:37:15 by obahi             #+#    #+#             */
/*   Updated: 2023/01/21 13:16:54 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<sys/wait.h>
# include<stdio.h>
# include"libft/libft.h"
# include <errno.h>
# include <fcntl.h>

typedef struct s_execve{
	char	**envp;
	char	**args;
	char	*cmd;
	int		t1;
	int		i;
	int		t2;
}	t_execve;

void		ft_clean(t_execve *exec1, t_execve *exec2);
void		ft_close(int t[2]);
char		*ft_cmd(char *cmd, char **path);
void		ft_dup2(int i, int j);
void		ft_execve(t_execve *exec);
void		ft_fork(t_execve *exe);
void		ft_free(char **ptr);
t_execve	*ft_initialize(char **envp, char *argv, int t[2], int i);
void		ft_open(int *fd, char *path, int oflag, mode_t mode);
char		**ft_path(char **envp);
void		ft_pipe(int t[2]);

#endif