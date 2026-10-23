/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:59:36 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/23 20:28:22 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_len(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putbase(long n, const char *base)
{
	int		count;
	int		len;

	count = 0;
	len = str_len(base);
	if (n < 0)
		n = -n;
	if (n >= (long)len)
		count += ft_putbase(n / len, base);
	count += ft_putchar(base[n % len]);
	return (count);
}
