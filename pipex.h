/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:37:15 by obahi             #+#    #+#             */
/*   Updated: 2023/01/17 14:42:52 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include<unistd.h>
# include<sys/wait.h>
# include<stdio.h>
# include"libft/libft.h"

void	ft_free(char **ptr);
char	**ft_path(char **envp);
char	*ft_cmd(char *cmd, char **path);

#endif