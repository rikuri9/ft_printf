/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 16:59:36 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/26 19:32:08 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
