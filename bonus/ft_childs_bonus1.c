/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs_bonus1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:37:37 by tliot             #+#    #+#             */
/*   Updated: 2022/07/04 10:37:55 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_path(char **paths, char **cmd_arg)
{
	char	*path;
	int		i;

	path = NULL;
	i = 0;
	while (paths[i] != NULL)
	{
		path = ft_strjoin_path(paths[i], cmd_arg[0]);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}

void	dup2_double(int zero, int un)
{
	dup2(zero, 0);
	dup2(un, 1);
}

void	ft_childs(t_pipex pipex, int i)
{
	if (pipex.n_cmd - 1 == 2)
		dup2_double(pipex.infile, pipex.outfile);
	else if (i == 2)
		dup2_double(pipex.infile, ft_lstlast(pipex.cmd)->pipe[1]);
	else if (i == pipex.n_cmd - 1)
		dup2_double(ft_lst_avant_dernier_last(pipex.cmd)->pipe[0],
			pipex.outfile);
	else if (i > 2 && i < pipex.n_cmd - 1)
		dup2_double(ft_lst_avant_dernier_last(pipex.cmd)->pipe[0],
			ft_lstlast(pipex.cmd)->pipe[1]);
	ft_lst_close_pipe(pipex.cmd);
	if (!ft_lstlast(pipex.cmd)->cmd)
	{
		perror(ft_lstlast(pipex.cmd)->arg_cmd[0]);
		ft_free_all(pipex);
		exit(1);
	}
	if (execve(ft_lstlast(pipex.cmd)->cmd,
			ft_lstlast(pipex.cmd)->arg_cmd, pipex.envp) == -1)
		perror("Error execve\n");
}
