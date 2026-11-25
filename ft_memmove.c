/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 21:01:47 by shur              #+#    #+#             */
/*   Updated: 2026/11/19 14:37:29 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	forward(unsigned char *pd, const unsigned char *ps, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		pd[i] = ps[i];
		i++;
	}
}

static void	backward(unsigned char *pd, const unsigned char *ps, size_t n)
{
	size_t	i;

	i = n;
	while (i > 0)
	{
		pd[i - 1] = ps[i - 1];
		i--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pd;
	const unsigned char	*ps;

	pd = dest;
	ps = src;
	if (pd == ps || n == 0)
		return (dest);
	if (pd < ps)
	{
		forward(pd, ps, n);
	}
	else
	{
		backward(pd, ps, n);
	}
	return (dest);
}
