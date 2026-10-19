/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:00:37 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/18 19:05:28 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	foo(char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	while (fmt != NULL)
	{
		printf("%s\n", fmt);
		fmt = va_arg(ap, char *);
	}
	va_end(ap);
}

int	main(void)
{
	foo("aiueo", "test", "aaaaaa", NULL);
	return (0);
}
 