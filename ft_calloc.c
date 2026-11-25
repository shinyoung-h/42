/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 20:38:05 by shur              #+#    #+#             */
/*   Updated: 2026/11/21 13:19:31 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	len;

	if (size > 0 && nmemb > 0)
	{
		if (nmemb > SIZE_MAX / size)
		{
			errno = ENOMEM;
			return (NULL);
		}
		else
		{
			len = nmemb * size;
		}
	}
	else
	{
		len = 1;
	}
	ptr = malloc(len);
	if (ptr != NULL)
		ft_bzero(ptr, len);
	return (ptr);
}
