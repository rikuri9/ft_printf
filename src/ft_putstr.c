/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 19:41:36 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/26 19:31:44 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
