/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:04:26 by abahja            #+#    #+#             */
/*   Updated: 2025/02/08 14:43:37 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

extern char	**environ;

t_token	*input_checker(int ac)
{
	t_token	*token;

	token = NULL;
	if (ac != 5)
	{
		if (ac > 5)
			write(2, "state : too many args \n", 24);
		else if (ac < 5)
			write(2, "state : few args \n", 23);
		write(2, "usage : ./pipex [infile] [cmd1] [cmd2] [outfile] \n", 51);
		exit(1);
	}
	else
		token_init(&token);
	return (token);
}

int	main(int ac, char **av)
{
	t_token	*token;

	token = input_checker(ac);
	empty_string(av, &token);
	parcer_token(av, environ, &token);
	token_genrator(&token);
	pipex(&token, av, environ);
	free_tokex(&token);
}
