/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:29:42 by abahja            #+#    #+#             */
/*   Updated: 2025/02/08 14:46:47 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cw(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

void	free_split(char **split, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
		free(split[i++]);
	free(split);
}

static int	ft_mc(char **card, char const *s, char sep)
{
	size_t	i;
	size_t	j;
	size_t	c_index;

	i = 0;
	c_index = 0;
	while (s[i])
	{
		if (s[i] == sep && ++i)
			continue ;
		j = i;
		while (s[i] && s[i] != sep)
			i++;
		card[c_index] = ft_substr(s, j, (i - j));
		if (!card[c_index])
		{
			free_split(card, c_index);
			return (0);
		}
		c_index++;
	}
	return (1);
}

void	write_error(void)
{
	write(2, "split error : what are u tryna to do", 37);
	write(2, "\n btw memory may be dumped", 27);
	exit(1);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	cw;

	if (!s || !*s)
		return (NULL);
	cw = ft_cw(s, c);
	ret = malloc(sizeof(char *) * (cw + 1));
	if (!ret)
		return (NULL);
	if (!ft_mc(ret, s, c))
		return (NULL);
	ret[cw] = 0;
	if (!ret)
		write_error();
	return (ret);
}
