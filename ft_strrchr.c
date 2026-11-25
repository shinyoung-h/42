/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 12:08:03 by shur              #+#    #+#             */
/*   Updated: 2026/11/18 12:33:41 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;
	size_t		i;

	p = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			p = &s[i];
		i++;
	}
	if (s[i] == c)
		p = &s[i];
	return ((char *)p);
}
