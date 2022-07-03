/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:07:18 by tliot             #+#    #+#             */
/*   Updated: 2022/06/24 17:26:08 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *ft_path(char **paths, char **cmd_arg)
{
    char *path; 
    int i;
    
    path = NULL;
    
    i = 0;
    while (paths[i] != NULL)
    {
        path = ft_strjoin_path(paths[i], cmd_arg[0]);
        if(access(path,X_OK) == 0)
            return(path);
        free(path);
        i++;
    }
    return(NULL);
}

void ft_child1(t_pipex pipex, char **argv, char **envp)
{
    dup2(pipex.tub[1],1);
    close(pipex.tub[0]);
    dup2(pipex.infile,0);

    pipex.cmd_arg = ft_split(argv[2], ' ');
    pipex.cmd = ft_path(pipex.paths, pipex.cmd_arg);
    if(!pipex.cmd)
    {
        ft_cmd_not_fond(pipex);
        ft_free_child(pipex);
        exit(1);
    }
    if(execve( pipex.cmd, pipex.cmd_arg, envp) == -1)
            perror("Error execve\n");
}

void ft_child2(t_pipex pipex, char **argv, char **envp)
{
    dup2(pipex.tub[0],0);
    close(pipex.tub[1]);
    dup2(pipex.outfile,1);

    pipex.cmd_arg = ft_split(argv[3], ' ');
    pipex.cmd = ft_path(pipex.paths, pipex.cmd_arg);
    if(!pipex.cmd)
    {
        ft_cmd_not_fond(pipex);
        ft_free_child(pipex);
        exit(1);
    }
    if(execve(pipex.cmd, pipex.cmd_arg, envp) == -1)
            perror("Error execve\n");
}