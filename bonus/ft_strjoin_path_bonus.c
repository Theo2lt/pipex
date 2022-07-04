/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_path_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:31:31 by tliot             #+#    #+#             */
/*   Updated: 2022/07/04 10:46:01 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin_path(char *s1, char *s2)
{
	int		i;
	int		len1;
	char	*str;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		str = (char *)malloc(sizeof(char) * (len1 + ft_strlen(s2) + 2));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		str[len1] = '/';
		i = -1;
		while (s2[++i])
		{
			str[len1 + 1] = s2[i];
			len1++;
		}
		str[len1 + 1] = '\0';
		return (str);
	}
	return (NULL);
}
