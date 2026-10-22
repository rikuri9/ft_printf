/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:00:37 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/22 20:04:51 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

static void	to_convert(char spec, va_list *ap)
{
	if (spec == 'c')
		ft_putchar(va_arg(*ap, int));
	else if (spec == 's')
		ft_putstr(va_arg(*ap, char *));
	//if (spec == 'p')

	if (spec == 'd' || spec == 'i')
		ft_putnbr(va_arg(*ap, int));
	//if (spec == 'u')

	//if (spec == 'x')

	//if (spec == 'X')

	else if (spec == '%')
		ft_putchar('%');

}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		size;

	size = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
			to_convert(*(++fmt), &ap);
		else
			ft_putchar(*fmt);
		fmt++;
	}
	va_end(ap);
	return (size);
}

//if (*fmt == '%')
//		{
//			va_copy(dest, ap);
//			if (*(fmt + 1) == 's')
//				write(1, va_arg(ap, char *), ft_strlen(va_arg(dest, char *)));
//			else if (*(fmt + 1) == 'c')
//			{
//				c = (char)va_arg(ap, int);
//				write(1, &c, 1);
//				fmt++;
//			}
//			else
//				write(1, fmt, 1);
//		}
//		else
//			write(1, fmt, 1);