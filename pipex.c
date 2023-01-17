/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obahi <obahi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:06:46 by obahi             #+#    #+#             */
/*   Updated: 2023/01/17 14:38:24 by obahi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void    ft_free(char **ptr)
{
    free(*ptr);
    *ptr = 0;
}

char    **ft_path(char  **envp)
{
    char    *paths;
    char    **path;
    int     i;

    if (!envp)
        return (0);
    i = 0;
    while (*(envp + i))
    {
        if (!ft_strncmp(*(envp + i), "PATH", 4))
        {
            paths = ft_strdup(*(envp + i) + 5);
            break;
        }
        i++;
    }
    path = ft_split(paths, ':');
    i = 0;
    while (*(path + i))
    {
        *(path + i) = ft_strjoin(*(path + i), "/");
        i++;
    }
    free(paths);
    return (path);
}

char    *ft_cmd(char *cmd, char **path)
{
    char    *tmp;
    char    *cmmd;
    int     i;

    if (!path)
        return (0);
    i = 0;
    while (*(path + i))
    {
        tmp = ft_strjoin(*(path + i), cmd);
        if (!access(tmp, F_OK | X_OK))
        {
            cmmd = tmp;
            free(tmp);
            break;
        }
        free(tmp);
        i++;
    }
    return (cmmd);
}

int main(int argc, char **argv, char **envp)
{
    char    **path;
    char    *cmd;
    int     i;

    path = ft_path(envp);
    cmd = ft_cmd("ls", path);
    printf("%s", cmd);
    while(1);
}

// char    *get_path(char *cmd, char **envp)
// {
//     char    *path;
//     char    *tmp;
//     char    **paths;
//     int     i;

//     i = 0;
//     tmp = cmd;
//     cmd = ft_strjoin("/", cmd);
//     ft_free(&tmp);
//     while (*(envp + i))
//     {
//         if (!ft_strncmp(*(envp + i), "PATH", 4))
//         {
//             path = ft_strdup(*(envp + i) + 5);
//             break;
//         }
//         i++;
//     }
//     paths = ft_split(path, ':');
//     ft_free(&path);
//     i = 0;
//     while (*(paths + i))
//     {
//         tmp = cmd;
//         cmd = ft_strjoin(*(paths + i), tmp);
//         if (!access(tmp, F_OK | X_OK))
//         {
//             free(cmd);
//             cmd = tmp;
//             break;
//         }
//         i++;
//     }
//     return (cmd);
// }
// int main(int argc, char ** argv, char **envp)
// {
//     //./pipex "ls -l"
//     char    *cmd;
//     char    **args;
//     char    *tmp;
//     char    *path;
//     char    **paths;
//     int     i;
//     pid_t   id;
//     int     status;
//     if (argc == 2)
//     {
//         args = ft_split(*(argv + 1), ' ');
//         // i = 0;
//         // while (*(args + i))
//         // {
//         //     printf("%s \n",*(args + i));
//         //     i++;
//         // }
//         cmd = get_path(*args, envp);
//         // cmd = *args;
//         // tmp = cmd;
//         // cmd = ft_strjoin("/", cmd);
//         // free(tmp);
//         // tmp = 0;
//         // // printf("%s \n",cmd);
//         // i = 0;
//         // while (*(envp + i))
//         // {
//         //     if (!ft_strncmp(*(envp + i), "PATH", 4))
//         //     {
//         //         path = ft_strdup(*(envp + i) + 5);
//         //         break;
//         //     }
//         //     i++;
//         // }
//         // paths = ft_split(path, ':');
//         // i = 0;
//         // while (*(paths + i))
//         // {
//         //     tmp = ft_strjoin(*(paths + i), cmd);
//         //     if (!access(tmp, F_OK | X_OK))
//         //     {
//         //         free(cmd);
//         //         cmd = tmp;
//         //         break;
//         //     }
//         //     i++;
//         // }
//         // // printf("%s ",cmd);
//         // free(path);
//         id = fork();
//         if (id >= 0)
//         {
//             if (!id)
//             {
//                 execve(cmd, args, 0);
//             }
//         }
//         else
//         {
//             wait(&status);
//         }   
//     }
// }