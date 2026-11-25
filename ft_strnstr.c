/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 13:18:12 by shur              #+#    #+#             */
/*   Updated: 2026/11/19 20:37:51 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*prerequisite(const char *big)
{
	if (big != NULL)
	{
		return ((char *) big);
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;
	size_t	len_big;

	i = 0;
	if (little == NULL || ft_strlen(little) == 0)
	{
		return (prerequisite(big));
	}
	len_little = ft_strlen(little);
	if (big == NULL || ft_strlen(big) < len_little)
		return (NULL);
	len_big = ft_strlen(big);
	while (big[i] && i < len && i < len_big - len_little)
	{
		if (ft_strncmp(&big[i], little, len_little) == 0)
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
