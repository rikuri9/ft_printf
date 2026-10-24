/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:00:37 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/24 12:34:55 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	to_convert(char spec, va_list *ap)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (spec == 'p')
		return (ft_putptr(va_arg(*ap, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr((long)va_arg(*ap, int)));
	if (spec == 'u')
		return (ft_putbase(va_arg(*ap, unsigned int),
				"0123456789"));
	if (spec == 'x')
		return (ft_putbase(va_arg(*ap, unsigned int),
				"0123456789abcdef"));
	if (spec == 'X')
		return (ft_putbase(va_arg(*ap, unsigned int),
				"0123456789ABCDEF"));
	if (spec == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
			count += to_convert(*(++fmt), &ap);
		else
			count += ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (count);
}
