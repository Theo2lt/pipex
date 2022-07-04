/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:53:38 by tliot             #+#    #+#             */
/*   Updated: 2022/07/04 15:00:11 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_all(t_pipex pipex)
{
	int	i;

	i = 0;
	while (pipex.paths[i])
	{
		free(pipex.paths[i]);
		i++;
	}
	free(pipex.paths);
	close(pipex.infile);
	close(pipex.outfile);
	ft_lst_free(pipex.cmd);
}

void	ft_lst_free(t_cmd *lst)
{
	t_cmd	*lst2;

	while (lst)
	{
		lst2 = lst;
		lst = lst->next;
		if (lst2->cmd)
			free(lst2->cmd);
		if (lst2->arg_cmd)
			ft_free(lst2->arg_cmd);
		free(lst2);
	}
}
