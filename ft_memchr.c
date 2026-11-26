/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:17:12 by shur              #+#    #+#             */
/*   Updated: 2026/11/18 21:08:58 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	ps = (unsigned char *) s;
	i = 0;
	while (i < n && ps[i])
	{
		if (ps[i] == c)
		{
			return ((void *) &ps[i]);
		}
		i++;
	}
	return (NULL);
}
