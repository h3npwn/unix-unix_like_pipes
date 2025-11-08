/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahja <abahja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 17:53:35 by abahja            #+#    #+#             */
/*   Updated: 2024/11/03 08:28:42 by abahja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	s_os;
	char	*dup;

	s_os = ft_strlen(s) + 1;
	dup = (char *)malloc(s_os * sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, s_os);
	return (dup);
}
