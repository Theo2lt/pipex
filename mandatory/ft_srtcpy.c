/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srtcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:12:17 by tliot             #+#    #+#             */
/*   Updated: 2022/07/09 10:56:00 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_strcpy(char *src)
{
	char	*cpy;
	int		i;
	int		len;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	cpy = (char *)malloc(sizeof(char *) * len);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		cpy[i] = src[i];
		i++;
	}
	return (cpy);
}
