/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:40:56 by riwamoto          #+#    #+#             */
/*   Updated: 2026/11/01 13:10:23 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(STDOUT_FILENO, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	count;
	size_t	len;
	size_t	ret;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (len > INT_MAX)
		return (-1);
	count = 0;
	while (count < len)
	{
		ret = write(STDOUT_FILENO, s + count, len - count);
		if (ret <= 0)
			return (-1);
		count += ret;
	}
	return ((int)count);
}
