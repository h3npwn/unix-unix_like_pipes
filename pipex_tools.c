/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:55:35 by abahja            #+#    #+#             */
/*   Updated: 2025/02/08 15:14:16 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_finder(char **envp, char **target, t_token **token)
{
	int		i;

	i = 0;
	*target = NULL;
	while (envp[i])
	{
		*target = ft_strnstr(envp[i], "PATH=", 5);
		if (*target)
			break ;
		i++;
	}
	if (*target != NULL)
		*target = *target + 5;
	else
		no_path('y', token);
}

char	**path_parcer(char *input)
{
	char	**path;

	if (!input || !*input)
		malloc_fail('y');
	path = ft_split (input, ':');
	if (!path || !*path)
		malloc_fail('y');
	return (path);
}

char	*ft_pathgiver(char *str1, char *str2)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(str1, "/");
	if (!temp)
		malloc_fail('y');
	path = ft_strjoin(temp, str2);
	if (!path)
	{
		free(temp);
		malloc_fail('y');
	}
	free(temp);
	return (path);
}

char	*cmdfinder(char **dir, char *target)
{
	int		i;
	char	*pifon;

	i = 0;
	if (!target || !*target)
	{
		malloc_fail('y');
		return (NULL);
	}
	while (dir[i])
	{
		pifon = ft_pathgiver(dir[i], target);
		if (access(pifon, X_OK) == 0)
			return (pifon);
		else if (errno == EACCES)
			return (pifon);
		free(pifon);
		i++;
	}
	return (NULL);
}

void	parcer_token(char **av, char **env, t_token **token)
{
	char	*path;
	char	**dir;

	path_finder(env, &path, token);
	dir = path_parcer(path);
	sub_parcing(token, av);
	main_parcing(token, av);
	if ((*token)->absp[0] == 0 && (*token)->e_str1 == 0)
		(*token)->cmdpath1 = cmdfinder(dir, (*token)->args1[0]);
	if ((*token)->absp[1] == 0 && (*token)->e_str2 == 0)
		(*token)->cmdpath2 = cmdfinder(dir, (*token)->args2[0]);
	free_dir(dir);
}
