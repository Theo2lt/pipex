/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:39:34 by tliot             #+#    #+#             */
/*   Updated: 2022/06/27 15:35:02 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	if(argc != 5)
		return (0);
	(void) argv;

	///// OPEN FILE FD ///////
	
	pipex.infile = open(argv[1], O_RDONLY);
	if(pipex.infile == -1)
		perror(argv[1]);
		
	pipex.outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	if(pipex.outfile == -1)
		perror(argv[4]);
	
	// OUVERTURE PIPE //
	if(pipe(pipex.tub) == 1)
		ft_putstr("ERR\n",2);
	
	/// PATH ET ENVP /// 
	pipex.envp = envp;
	pipex.paths = ft_split(ft_find_paths(envp)+5,':');

	/// FORK ///
	if(pipex.infile != -1)
	{
		pipex.pid1 = fork();
		if(pipex.pid1 == 0)
			ft_child1(pipex, argv, envp);
	}
	
	if(pipex.outfile != -1)
	{ 
		pipex.pid2 = fork();
		if(pipex.pid2 == 0)
			ft_child2(pipex, argv, envp);
	}
	close(pipex.tub[0]);
	close(pipex.tub[1]);
	
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);

	ft_free_papa(pipex);
	return(0);
	
}
