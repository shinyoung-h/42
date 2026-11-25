/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@42berlin.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:39:18 by shur              #+#    #+#             */
/*   Updated: 2026/11/24 14:18:19 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*buf;

	i = 0;
	buf = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (s[i] > '\0')
	{
		buf[i] = f(i, s[i]);
		i++;
	}
	return (buf);
}
