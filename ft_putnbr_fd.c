/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@42berlin.de>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:56:26 by shur              #+#    #+#             */
/*   Updated: 2026/11/26 17:05:45 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_num(int n, int fd)
{
	char	num;

	if (n > 0)
	{
		print_num(n / 10, fd);
		num = (n % 10) + '0';
		write(fd, &num, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	print_num(n, fd);
}
