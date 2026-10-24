/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:26:45 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/24 11:38:45 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(char *s)
{
	int	count;

	if (s == NULL)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	count += ft_putbase((unsigned long)s, "0123456789abcdef");
	return (count);
}
