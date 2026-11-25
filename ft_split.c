/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 20:41:38 by shur              #+#    #+#             */
/*   Updated: 2026/11/24 15:46:44 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	word_count(char const *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	k;

	count = 0;
	i = 0;
	while (s[i])
	{
		k = get_len_word(&s[i], c);
		if (k == 0)
		{
			i++;
		}
		else
		{
			i = i + k;
			count++;
		}
	}
	return (count);
}

static int	free_2d(char **buf, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(buf[i]);
		i++;
	}
	free(buf);
	return (0);
}

static int	write_buf(char **buf, char const *s, char c)
{
	size_t	i;
	size_t	w;
	size_t	k;

	i = 0;
	w = 0;
	while (s[i])
	{
		k = get_len_word(&s[i], c);
		if (k == 0)
			i++;
		else
		{
			buf[w] = malloc(sizeof(char) * (k + 1));
			if (buf[w] == NULL)
				return (free_2d(buf, w));
			ft_strlcpy(buf[w], &s[i], k + 1);
			w++;
			i = i + k;
		}
	}
	buf[w] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**buf;

	i = 0;
	count = word_count(s, c);
	buf = malloc(sizeof(char *) * (count + 1));
	if (buf == NULL)
		return (NULL);
	if (write_buf(buf, s, c) == 0)
		return (NULL);
	return (buf);
}
