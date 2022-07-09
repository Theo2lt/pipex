/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:37:37 by tliot             #+#    #+#             */
/*   Updated: 2022/07/09 12:09:09 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char **paths, char **cmd_arg)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	if (paths)
	{
		while (paths[i] != NULL)
		{
			path = ft_strjoin_path(paths[i], cmd_arg[0]);
			if (path && access(path, X_OK) == 0)
				return (path);
			free(path);
			i++;
		}
	}
	if (access(cmd_arg[0], X_OK) == 0)
		return (ft_strcpy(cmd_arg[0]));
	return (NULL);
}

void	dup2_double(int zero, int un)
{
	dup2(zero, 0);
	dup2(un, 1);
}

void	ft_exec(t_pipex pipex)
{
	if (pipex.infile == -1 && ft_lstlast(pipex.cmd)->num_cmd == 2)
	{
		ft_free_all(pipex);
		exit(1);
	}
	if (!ft_lstlast(pipex.cmd)->cmd)
	{
		if (!ft_lstlast(pipex.cmd)->cmd)
			ft_commande_not_found(pipex);
		ft_free_all(pipex);
		exit(1);
	}
	if (execve(ft_lstlast(pipex.cmd)->cmd,
			ft_lstlast(pipex.cmd)->arg_cmd, pipex.envp) == -1)
		perror("Error execve\n");
}

void	ft_exit(t_pipex pipex)
{
	ft_lst_close_pipe(pipex.cmd);
	ft_free_all(pipex);
	exit(1);
}

void	ft_childs(t_pipex pipex, int i)
{
	if (pipex.n_cmd - 1 == 2)
	{
		if (pipex.infile == -1)
			ft_exit(pipex);
		dup2_double(pipex.infile, pipex.outfile);
	}
	else if (i == 2)
	{
		if (pipex.infile == -1)
			ft_exit(pipex);
		dup2_double(pipex.infile, ft_lstlast(pipex.cmd)->pipe[1]);
	}
	else if (i == pipex.n_cmd - 1)
	{
		dup2_double(ft_lst_avant_dernier_last(pipex.cmd)->pipe[0],
			pipex.outfile);
		if (pipex.outfile == -1)
			ft_exit(pipex);
	}
	else if (i > 2 && i < pipex.n_cmd - 1)
		dup2_double(ft_lst_avant_dernier_last(pipex.cmd)->pipe[0],
			ft_lstlast(pipex.cmd)->pipe[1]);
	ft_lst_close_pipe(pipex.cmd);
	ft_exec(pipex);
}
