/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:08:52 by abahja            #+#    #+#             */
/*   Updated: 2025/02/08 14:59:03 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	token_init(t_token **token)
{
	*token = (t_token *)malloc(sizeof(t_token));
	if (token == NULL)
		malloc_fail('y');
	(*token)->args1 = NULL;
	(*token)->args2 = NULL;
	(*token)->cmdpath1 = NULL;
	(*token)->cmdpath2 = NULL;
	(*token)->absp[0] = 0;
	(*token)->absp[1] = 0;
	(*token)->e_str1 = 0;
	(*token)->e_str2 = 0;
}

void	token_genrator(t_token **token)
{
	if ((*token)->args1 != NULL)
	{
		if ((*token)->absp[0] == 0)
		{
			free((*token)->args1[0]);
			(*token)->args1[0] = (*token)->cmdpath1;
			(*token)->cmdpath1 = NULL;
		}
	}
	if ((*token)->args2 != NULL)
	{
		if ((*token)->absp[1] == 0)
		{
			free((*token)->args2[0]);
			(*token)->args2[0] = (*token)->cmdpath2;
			(*token)->cmdpath2 = NULL;
		}
	}
}

void	empty_string(char **av, t_token **token)
{
	char	*s;
	char	*x;

	s = av[2];
	x = av[3];
	if (*s == 0)
		(*token)->e_str1 = 1;
	if (*x == 0)
		(*token)->e_str2 = 1;
}

void	free_tokex(t_token **token)
{
	int	i;

	i = 0;
	if (!token || !*token)
		return ;
	if ((*token)->args1)
	{
		while ((*token)->args1[i])
			free((*token)->args1[i++]);
		free((*token)->args1);
	}
	i = 0;
	if ((*token)->args2)
	{
		while ((*token)->args2[i])
			free((*token)->args2[i++]);
		free((*token)->args2);
	}
	free(*token);
	*token = NULL;
}
