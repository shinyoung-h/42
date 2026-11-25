/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@42berlin.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:01:34 by shur              #+#    #+#             */
/*   Updated: 2026/11/24 20:16:42 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*curr;
	t_list	*succ;

	if (!lst || !del)
		return ;
	curr = *lst;
	while (curr->next != NULL)
	{
		succ = curr->next;
		ft_lstdelone(curr, del);
		curr = succ;
	}
	ft_lstdelone(curr, del);
	free(lst);
}
