/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finalstep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:40:47 by abahja            #+#    #+#             */
/*   Updated: 2025/02/08 16:24:10 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	sub_process(t_token **token, char **av, char **env)
{
	int	in_fd;

	in_fd = open(av[1], O_RDONLY);
	if (in_fd == -1)
		files_erro(token, 0, av[1]);
	if ((*token)->e_str1 || !(*token)->args1[0]
		|| access((*token)->args1[0], X_OK) == -1)
		cmd_err(token, errno, (*token)->e_str1);
	if (dup2(in_fd, STDIN_FILENO) == -1)
		red_fails(token);
	close(in_fd);
	dup2((*token)->pipe_fd[1], STDOUT_FILENO);
	close((*token)->pipe_fd[0]);
	close((*token)->pipe_fd[1]);
	execve((*token)->args1[0], (*token)->args1, env);
	free_tokex(token);
	exit(1);
}

void	main_process(t_token **token, char **av, char **env)
{
	int	out_fd;

	out_fd = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (out_fd == -1)
		files_erro(token, 1, av[4]);
	if ((*token)->e_str2 || !(*token)->args2[0]
		|| access((*token)->args2[0], X_OK) == -1)
		cmd_err(token, errno, (*token)->e_str2);
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		red_fails(token);
	close(out_fd);
	dup2((*token)->pipe_fd[0], STDIN_FILENO);
	close((*token)->pipe_fd[0]);
	close((*token)->pipe_fd[1]);
	execve((*token)->args2[0], (*token)->args2, env);
	free_tokex(token);
	exit(1);
}

void	end(t_token **token, int exitcode)
{
	free_tokex(token);
	exit ((exitcode >> 8));
}

void	pipex(t_token **token, char **av, char **env)
{
	pid_t	pid[2];
	int		exitcode;

	if (pipe((*token)->pipe_fd) == -1)
		red_fails(token);
	pid[0] = fork();
	if (pid[0] == -1)
		red_fails(token);
	if (pid[0] == 0)
		sub_process(token, av, env);
	pid[1] = fork();
	if (pid[1] == -1)
		red_fails(token);
	if (pid[1] == 0)
		main_process(token, av, env);
	close((*token)->pipe_fd[0]);
	close((*token)->pipe_fd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &exitcode, 0);
	end(token, exitcode);
}
