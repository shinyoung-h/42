/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@42berlin.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 18:38:18 by shur              #+#    #+#             */
/*   Updated: 2026/11/24 18:47:15 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	size_t	len;
	t_list	*cur;

	if (lst == NULL)
		return (0);
	len = 0;
	cur = lst;
	while (cur->next != NULL)
	{
		cur = cur->next;
		len++;
	}
	return (len);
}
