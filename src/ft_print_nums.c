/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:43:26 by riwamoto          #+#    #+#             */
/*   Updated: 2026/11/01 13:16:40 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(unsigned long n, const char *base)
{
	int				count;
	unsigned long	len;

	count = 0;
	len = (unsigned long)ft_strlen(base);
	if (n >= len)
		count += ft_putbase(n / len, base);
	count += ft_putchar(base[n % len]);
	return (count);
}

int	ft_putnbr(long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	count += ft_putbase((unsigned long)n, "0123456789");
	return (count);
}

int	ft_putptr(void *ptr)
{
	int			count;
	uintptr_t	addr;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	addr = (uintptr_t)ptr;
	count = ft_putstr("0x");
	count += ft_putbase((unsigned long)addr, "0123456789abcdef");
	return (count);
}
