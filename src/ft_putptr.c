/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:26:45 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/24 18:17:04 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putptr(void *ptr)
{
	int			count;
	uintptr_t	addr;

	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	addr = (uintptr_t)ptr;
	count = ft_putstr("0x");
	count += ft_putbase((unsigned long)addr, "0123456789abcdef");
	return (count);
}
