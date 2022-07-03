/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:53:38 by tliot             #+#    #+#             */
/*   Updated: 2022/07/04 00:00:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
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
void ft_close_pipe(t_pipex *pipex)
{
	close(pipex->tub[0]);
	close(pipex->tub[1]);
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

void ft_free_papa(t_pipex *pipex)
{
	int i;
	
	i = 0;
	while(pipex->paths[i])
	{
		free(pipex->paths[i]);
		i++;
	}
	free(pipex->paths);

	close(pipex->infile);
	close(pipex->outfile);
	
}