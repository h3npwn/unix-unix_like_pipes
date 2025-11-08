/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 10:11:50 by abahja            #+#    #+#             */
/*   Updated: 2025/02/08 15:14:32 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	is_dir(char *args)
{
	if (!args)
		return (0);
	if (ft_strchr(args, '/'))
		return (1);
	return (0);
}

void	free_dir(char **dir)
{
	int	i;

	i = 0;
	while (dir[i])
	{
		free(dir[i]);
		i++;
	}
	free(dir);
	dir = NULL;
}

void	sub_parcing(t_token **token, char **av)
{
	if ((*token)->e_str1 == 0)
	{
		(*token)->args1 = ft_split(av[2], ' ');
		if ((*token)->args1)
		{
			if (is_dir((*token)->args1[0]))
				(*token)->absp[0] = 1;
		}
		else
			malloc_fail('y');
	}
	return ;
}

void	main_parcing(t_token **token, char **av)
{
	if ((*token)->e_str2 == 0)
	{
		(*token)->args2 = ft_split(av[3], ' ');
		if ((*token)->args2)
		{
			if (is_dir((*token)->args2[0]))
				(*token)->absp[1] = 1;
		}
		else
			malloc_fail('y');
	}
	return ;
}
