/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:46:19 by tliot             #+#    #+#             */
/*   Updated: 2022/07/07 15:50:18 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_cmd	*ft_lstnew(int num_cmd, char *cmd_arg, t_pipex pipex)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->num_cmd = num_cmd;
	new->arg_cmd = ft_split(cmd_arg, ' ');
	new->cmd = ft_path(pipex.paths, new->arg_cmd);
	if (pipe(new->pipe))
		ft_putstr("ERROR", 2);
	new->pid = 0;
	new->next = NULL;
	return (new);
}

t_cmd	*ft_lstlast(t_cmd *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_cmd	*ft_lst_avant_dernier_last(t_cmd *lst)
{
	if (!lst->next)
		return (lst);
	else
	{
		while (lst)
		{
			if (!lst->next->next)
				return (lst);
			lst = lst->next;
		}
	}
	return (lst);
}

void	ft_lstadd_back(t_cmd **alst, t_cmd *new)
{
	t_cmd	*last;

	if (*alst)
	{
		last = ft_lstlast(*alst);
		last->next = new;
	}
	else
		*alst = new;
}

void	ft_lst_close_pipe(t_cmd *lst)
{
	while (lst)
	{
		close(lst->pipe[0]);
		close(lst->pipe[1]);
		lst = lst->next;
	}
}
