/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 17:06:48 by shur              #+#    #+#             */
/*   Updated: 2026/11/21 18:28:25 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	size_t	len_s1;
	size_t	len_s2;
	char	*dest;

	len_s1 = 0;
	len_s2 = 0;
	if (s1 != NULL)
		len_s1 = ft_strlen(s1);
	if (s2 != NULL)
		len_s2 = ft_strlen(s2);
	if (len_s1 > SIZE_MAX - len_s2)
		return (NULL);
	total_len = len_s1 + len_s2;
	dest = calloc(total_len + 1, sizeof(char));
	if (dest == NULL)
		return (NULL);
	if (s1 != NULL)
		ft_strlcpy(dest, s1, len_s1 + 1);
	if (s2 != NULL)
		ft_strlcat(dest, s2, total_len + 1);
	return (dest);
}
