/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@42berlin.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:17:13 by shur              #+#    #+#             */
/*   Updated: 2026/11/25 08:22:09 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_list(t_list *top, void (*del)(void *))
{
	t_list	*curr;
	t_list	*succ;

	if (!top)
		return ;
	curr = top;
	while (curr->next != NULL)
	{
		succ = curr->next;
		ft_lstdelone(curr, del);
		curr = succ;
	}
	ft_lstdelone(curr, del);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new;
	t_list	*top;

	if (!lst || !f || !del)
		return (NULL);
	curr = lst;
	top = NULL;
	while (curr->next != NULL)
	{
		new = ft_lstnew((*f)(curr->content));
		if (!new)
		{
			free_list(top, del);
			return (NULL);
		}
		if (!top)
			top = new;
		ft_lstback_add(&top, new);
		curr = curr->next;
	}
	return (top);
}
