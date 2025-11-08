/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:29:42 by abahja            #+#    #+#             */
/*   Updated: 2025/02/08 16:24:26 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	no_path(char fin, t_token **token)
{
	write(2, RED, 8);
	write(2, "xFATAL : NO[env]PATH found exiting...\n", 39);
	write(2, RESET, 4);
	if (fin == 'y')
	{
		if (*token)
			free(*token);
		exit(1);
	}
}

void	malloc_fail(char fin)
{
	write(2, RED, 8);
	write(2, "xFATAL : allocation failed memory may be dumped\n", 49);
	write(2, RESET, 4);
	if (fin == 'y')
		exit(1);
}

void	cmd_err(t_token **token, int err, int state)
{
	free_tokex(token);
	if (state == 1 || err == EACCES)
	{
		write(2, "shell : permission command denied\n", 35);
		exit (126);
	}
	else
	{
		write(2, "shell : command not found\n", 27);
		exit(127);
	}
}

void	files_erro(t_token **token, int io, char *filename)
{
	free_tokex(token);
	if (io == 0)
	{
		if (errno == ENOENT)
			write(2, "shell : no such file or dir : ", 31);
		else if (errno == EACCES)
			write(2, "shell : file permission denied : ", 34);
		write(2, RED, 8);
		write(2, filename, ft_strlen(filename));
		write(2, "\n", 1);
		write(2, RESET, 4);
		exit(1);
	}
	else if (io == 1)
	{
		write(2, "shell : no such file or directory : ", 37);
		write(2, RED, 8);
		write(2, filename, ft_strlen(filename));
		write(2, "\n", 1);
		write(2, RESET, 4);
	}
	exit(1);
}

void	red_fails(t_token **token)
{
	free_tokex(token);
	write(2, "FATAL : ", 9);
	write(2, RED, 8);
	write(2, "error during redirection", 25);
	write(2, "\n", 1);
	write(2, RESET, 4);
	exit(1);
}
