/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@42berlin.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:17:13 by shur              #+#    #+#             */
/*   Updated: 2026/11/26 12:17:08 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new;
	t_list	*top;

	if (!lst || !f || !del)
		return (NULL);
	curr = lst;
	top = NULL;
	while (curr != NULL)
	{
		new = ft_lstnew(f(curr->content));
		if (!new)
		{
			ft_lstclear(&top, del);
			return (NULL);
		}
		if (!top)
			top = new;
		else
			ft_lstadd_back(&top, new);
		curr = curr->next;
	}
	return (top);
}
