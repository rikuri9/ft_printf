/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:59:36 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/24 12:35:20 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	str_len(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	ft_putbase(unsigned long n, const char *base)
{
	int				count;
	unsigned long	len;

	count = 0;
	len = (unsigned long)str_len(base);
	if (n >= len)
		count += ft_putbase(n / len, base);
	count += ft_putchar(base[n % len]);
	return (count);
}
