/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:09:08 by tliot             #+#    #+#             */
/*   Updated: 2022/07/09 11:01:31 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
