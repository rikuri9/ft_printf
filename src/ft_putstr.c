/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:41:36 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/24 11:43:52 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
		count += ft_putchar(*s++);
	return (count);
}
