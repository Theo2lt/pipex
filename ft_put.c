/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:46:11 by tliot             #+#    #+#             */
/*   Updated: 2022/06/24 17:56:31 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putchar(char c, int fd) 
{
	write(fd, &c, 1);
}

void	ft_putstr(char *s, int fd)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i],fd);
		i++;
	}
}

void ft_cmd_not_fond(t_pipex pipex)
{
	    ft_putstr(ft_find_shell(pipex.envp), 2);
        ft_putstr(": command not found: ",2);
        ft_putstr(pipex.cmd_arg[0],2);
        ft_putstr("\n",2);
}

void ft_no_such_file(char **envp, char *str)
{
	    ft_putstr(ft_find_shell(envp), 2);
        ft_putstr(": no such file or directory: ",2);
        ft_putstr(str,2);
        ft_putstr("\n",2);
}