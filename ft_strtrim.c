/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 18:55:16 by shur              #+#    #+#             */
/*   Updated: 2026/11/22 19:16:38 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (in_set(s1[start], set))
	{
		start++;
	}
	return (start);
}

static int	get_end(char const *s1, char const *set, size_t end)
{
	while (in_set(s1[end], set))
	{
		end--;
	}
	return (end + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buf;
	size_t	len;
	size_t	start;
	size_t	end;

	len = 0;
	if (s1 != NULL)
		len = ft_strlen(s1);
	if (s1 != NULL && (set == NULL || ft_strlen(set) == 0))
		return (ft_strdup(s1));
	buf = ft_calloc(len + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	if (s1 == NULL)
		return (buf);
	start = get_start(s1, set);
	end = get_end(s1, set, len - 1);
	if (start < end)
	{
		ft_strlcpy(buf, &s1[start], end - start + 1);
	}
	return (buf);
}
