/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:53:38 by tliot             #+#    #+#             */
/*   Updated: 2022/07/03 21:01:54 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

/*
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
*/

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
	ft_lst_free(pipex.cmd);
}

void ft_lst_free(t_cmd *lst)
{
	t_cmd *lst2;
	
	while(lst)
	{
		lst2 = lst;
		lst = lst->next;
		if(lst2->cmd)
			free(lst2->cmd);

		ft_free(lst->arg_cmd);
		free(lst2);
		
	}
}