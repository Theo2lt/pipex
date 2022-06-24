/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:53:38 by tliot             #+#    #+#             */
/*   Updated: 2022/06/24 16:50:57 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_free(char **str)
{
    int i;

    i = 0;
    while (str[i] != NULL)
    {
        free(str[i]);
        i++;
    }
    free(str);
    
}

void ft_free_child(t_pipex pipex)
{
    int i;
    
    i = 0;
    while(pipex.cmd_arg[i])
    {
        free(pipex.cmd_arg[i]);
        i++;
    }
    free(pipex.cmd_arg);
    free(pipex.cmd);

}

void ft_free_papa(t_pipex pipex)
{
    int i;
    
    i = 0;
    while(pipex.paths[i])
    {
        free(pipex.paths[i]);
        i++;
    }
    free(pipex.paths);

    close(pipex.infile);
    close(pipex.outfile);
    
}