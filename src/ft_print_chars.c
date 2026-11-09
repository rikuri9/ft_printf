/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:40:56 by riwamoto          #+#    #+#             */
/*   Updated: 2026/11/07 11:50:06 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}

int	ft_putstr(const char *s)
{
	size_t	written;
	size_t	len;
	ssize_t	ret;

	if (s == NULL)
		return (ft_putstr("(null)"));
	len = ft_strlen(s);
	if (len > INT_MAX)
		return (-1);
	written = 0;
	while (written < len)
	{
		ret = write(STDOUT_FILENO, s + written, len - written);
		if (ret <= 0)
			return (-1);
		written += ret;
	}
	return (written);
}
