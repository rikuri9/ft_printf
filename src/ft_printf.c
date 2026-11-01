/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:00:37 by riwamoto          #+#    #+#             */
/*   Updated: 2026/11/01 12:52:33 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	to_convert(char spec, va_list *ap)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (spec == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	if (spec == 'p')
		return (ft_putptr(va_arg(*ap, void *)));
	if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
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
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		ret;

	count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (*++fmt == '\0')
				break ;
			ret = to_convert(*fmt++, &ap);
		}
		else
			ret = ft_putchar(*fmt++);
		if (ret < 0)
		{
			va_end(ap);
			return (-1);
		}
		count += ret;
	}
	va_end(ap);
	return (count);
}
