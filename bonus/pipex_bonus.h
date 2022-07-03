/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <tliot@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:39:22 by tliot             #+#    #+#             */
/*   Updated: 2022/07/03 20:54:35 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

typedef struct	s_cmd
{
	int		num_cmd;		// Position de la commande
	char	*cmd;			// CMD A EXECUTER 
	char	**arg_cmd;		// ARGUMENT DE LA COMMANDE
	int				pipe[2];	// ENTRÉ ET SORTIE DU PIPE
	pid_t	pid;			// PID DU FORK
	struct	s_cmd	*next;	// PROCHAINE ELEMENT DE LA LISTE CHAINÉ
}t_cmd;

typedef struct s_pipex
{
	int				infile;
	int				outfile;
	char			**envp;	// ENVIRONEMENT OS
	char			**paths;// ENVIRONEMENT EXECUTION
	char			**argv;	// ARGUMENT ./PIPEX_BONUS infile cmd1 cmd2 cmd3 outfile
	int				n_cmd;	// NOMBRE DE COMMANDE +1
	struct s_cmd	*cmd;
	
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

void	ft_child_inter(t_pipex pipex, char **argv, char **envp);

/// LISTE CHAINÉ ///
t_cmd *ft_lstnew(int num_cmd ,char *cmd_arg, t_pipex pipex);
t_cmd	*ft_lstlast(t_cmd *lst);
t_cmd	*ft_lst_avant_dernier_last(t_cmd *lst);
void	ft_lstadd_back(t_cmd **alst, t_cmd *new);

/// CHILD /// 

void ft_childs(t_pipex pipex, int i);

// CLOSE PIPE //
void ft_lst_close_pipe(t_cmd *lst);

/// DEBUG //
void ft_debug_cmd(t_pipex pipex);

// FREE //

void ft_lst_free(t_cmd *lst);
#endif