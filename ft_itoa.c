/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shur <shur@student.42berlin.de>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:50:08 by shur              #+#    #+#             */
/*   Updated: 2026/11/23 19:50:14 by shur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long num)
{
	int		len;
	long	n;

	n = num;
	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	to_ascii(long num)
{
	return ("0123456789"[num]);
}

static void	write_buf(char *buf, long num, int len)
{
	while (num > 0)
	{
		buf[len - 1] = to_ascii(num % 10);
		num /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*buf;

	num = (long) n;
	len = get_len(num);
	buf = ft_calloc(len + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	buf[len] = '\0';
	if (num == 0)
	{
		buf[0] = '0';
		return (buf);
	}
	if (num < 0)
	{
		num = -num;
		buf[0] = '-';
	}
	write_buf(buf, num, len);
	return (buf);
}
