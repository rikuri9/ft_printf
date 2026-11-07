/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:43:26 by riwamoto          #+#    #+#             */
/*   Updated: 2026/11/07 11:29:46 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(uintptr_t n, const char *base)
{
	int				count;
	int				ret;
	unsigned long	len;

	count = 0;
	len = ft_strlen(base);
	if (n >= len)
	{
		ret = ft_putbase(n / len, base);
		if (ret == -1)
			return (-1);
		count += ret;
	}
	ret = ft_putchar(base[n % len]);
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_putnbr(long n)
{
	int	count;
	int	ret;

	count = 0;
	if (n < 0)
	{
		ret = ft_putchar('-');
		if (ret == -1)
			return (-1);
		count += ret;
		n = -n;
	}
	ret = ft_putbase((uintptr_t)n, "0123456789");
	if (ret == -1)
		return (-1);
	count += ret;
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;
	int	ret;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	ret = ft_putbase((uintptr_t)ptr, "0123456789abcdef");
	if (ret == -1)
		return (-1);
	return (count + ret);
}
