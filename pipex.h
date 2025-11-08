/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:04:29 by abahja            #+#    #+#             */
/*   Updated: 2025/02/08 15:14:42 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"
# define WHITE "\033[0;37m"
# define YELL "\033[0;33m"
# define RESET "\033[0m"
# define RED "\033[1;31m"

typedef struct s_token{
	char	*cmdpath1;
	char	*cmdpath2;
	char	**args1;
	char	**args2;
	int		absp[2];
	int		pipe_fd[2];
	int		e_str1;
	int		e_str2;
}	t_token;

/*-------------errors------------------*/
# define NOENVPATH 77
# define EXPERR 333
# define NOENT 1337
/*-----------error*-----------------*/
void	no_path(char fin, t_token **token);
void	malloc_fail(char fin);
void	files_erro(t_token **token, int io, char *filename);
void	red_fails(t_token **token);
void	cmd_err(t_token **token, int err, int state);
void	free_dir(char **dir);
/*----------------tools to parce--------------------*/
void	token_init(t_token **token);
void	path_finder(char **envp, char **target, t_token **token);
char	**path_parcer(char *path);
char	*cmdfinder(char **pos_path, char *target);
void	sub_parcing(t_token **token, char **av);
void	main_parcing(t_token **token, char **av);
void	empty_string(char **av, t_token **token);
void	token_genrator(t_token **token);
/*----------check input file-----------*/
void	parcer_token(char **av, char **env, t_token **token);
void	free_tokex(t_token **token);
/*----------------main--------------------*/
void	pipex(t_token **token, char **av, char **env);
#endif