/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 20:09:40 by shur              #+#    #+#             */
/*   Updated: 2026/11/18 19:26:28 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// not optimized. The original return value is computed bitwise
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
