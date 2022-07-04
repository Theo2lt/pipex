/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:39:34 by tliot             #+#    #+#             */
/*   Updated: 2022/07/04 18:01:43 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_param_main(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->argv = argv;
	pipex->n_cmd = argc - 1;
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		perror(argv[1]);
	pipex->outfile = open(argv[pipex->n_cmd],
			O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (pipex->outfile == -1)
		perror(argv[pipex->n_cmd]);
	pipex->envp = envp;
	pipex->paths = ft_split(ft_find_paths(envp) + 5, ':');
	pipex->cmd = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		i;

	if (argc != 5)
		return (0);
	ft_param_main(&pipex, argc, argv, envp);
	i = 2;
	while (i <= pipex.n_cmd - 1)
	{	
		ft_lstadd_back(&pipex.cmd, ft_lstnew(i, argv[i], pipex));
		ft_lstlast(pipex.cmd)->pid = fork();
		if (ft_lstlast(pipex.cmd)->pid == 0)
			ft_childs(pipex, i);
		i++;
	}
	close(pipex.infile);
	close(pipex.outfile);
	ft_lst_close_pipe(pipex.cmd);
	ft_wait_all_pid(pipex.cmd);
	ft_free_all(pipex);
	return (0);
}

void	ft_wait_all_pid(t_cmd *lst)
{
	t_cmd	*lst2;

	lst2 = lst;
	while (lst2)
	{
		waitpid(lst2->pid, NULL, 0);
		lst2 = lst2->next;
	}
}
