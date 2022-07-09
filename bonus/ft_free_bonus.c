/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:53:38 by tliot             #+#    #+#             */
/*   Updated: 2022/07/07 15:51:05 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
	if (pipex.envp)
	{
		while (pipex.paths[i])
		{
			free(pipex.paths[i]);
			i++;
		}
		free(pipex.paths);
	}
	if (pipex.infile >= 0)
		close(pipex.infile);
	if (pipex.outfile >= 0)
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
