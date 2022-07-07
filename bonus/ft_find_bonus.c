/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:01:37 by tliot             #+#    #+#             */
/*   Updated: 2022/07/06 19:11:32 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_find_paths(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 4) != 0)
		i++;
	if (envp[i])
		return (NULL);
	//if (ft_strncmp(envp[i], "PATH=", 4) != 0)
	//	return (NULL);
	return (envp[i]);
}

char	*ft_find_shell(char **envp)
{
	int	i;
	int	y;

	i = 0;
	while (ft_strncmp(envp[i], "SHELL=", 5) != 0)
		i++;
	if (ft_strncmp(envp[i], "SHELL=", 5) != 0)
		return (NULL);
	y = 0;
	while (envp[i][y + 1])
		y++;
	while (envp[i][y])
	{
		if (envp[i][y] != '/')
			y--;
		else
			return (envp[i] + y + 1);
	}
	return (envp[i]);
}
