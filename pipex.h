/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:39:22 by tliot             #+#    #+#             */
/*   Updated: 2022/06/24 17:57:12 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_pipex
{
    int infile;
    int outfile;
    int tub[2];
    char **envp;
    char **paths;
    pid_t pid1;
    pid_t pid2;
    char *cmd;
    char **cmd_arg;
    
}t_pipex;

int     cmp_char(char c1, char c2);
int     ft_strncmp(char *s1, char *s2, int n);
char    *ft_find_paths(char **envp);
char    *ft_path(char **envp, char **argVec);
int     ft_strlen(const char *s);
int     count_words(const char *str, char c);
char	*word_dup(const char *str, int start, int finish);
char	**ft_split(char const *s, char c);
void    ft_free(char **str);
char	*ft_strjoin_path(char *s1, char *s2);
void	ft_putchar(char c, int fd);
void	ft_putstr(char *s, int fd);
void    ft_child1(t_pipex pipex, char **argv, char **envp);
void    ft_child2(t_pipex pipex, char **argv, char **envp);
void    ft_free_child(t_pipex pipex);
void    ft_free_papa(t_pipex pipex);
char    *ft_find_shell(char **envp);
void    ft_cmd_not_fond(t_pipex pipex);
void    ft_no_such_file(char **envp, char *str);

#endif