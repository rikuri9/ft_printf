/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:50:27 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/22 20:16:58 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*s1 = "forty";
	char	*s2 = NULL;
	char	c1 = '4';
	char	c2 = '2';
	int		d = -2147483648;
	int		i = 2147483647;

	ft_printf("Hello world %c two %c", c1, c2);
	printf(" \n\n");
	printf("Hello world %c two %c", c1, c2);
	printf(" \n\n");
	ft_printf("Hello world %s two %s", s1, s2);
	printf(" \n\n");
	printf("Hello world %s two %s", s1, s2);
	printf(" \n\n");
	//ft_printf("Hello world %p two %p", p1, p2);
	//printf(" \n\n");
	//printf("Hello world %p two %p", p1, p2);
	//printf(" \n\n");
	ft_printf("Hello world %d two %i", d, i);
	printf(" \n\n");
	printf("Hello world %d two %i", d, i);
	printf(" \n\n");
	ft_printf("Hello world %u two %u", d, i);
	printf(" \n\n");
	printf("Hello world %u two %u", d, i);
	printf(" \n\n");
	//ft_printf("Hello world %x two %x", d, i);
	//printf(" \n\n");
	printf("Hello world %x two %x", d, i);
	printf(" \n\n");
	//ft_printf("Hello world %X two %X", d, i);
	//printf(" \n\n");
	printf("Hello world %X two %X", d, i);
	printf(" \n\n");
	ft_printf("Hello world %% two %%");
	printf(" \n\n");
	printf("Hello world %% two %%");
	printf(" \n\n");
	return (0);
}
