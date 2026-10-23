/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 16:50:27 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/23 20:31:50 by riwamoto         ###   ########.fr       */
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
	char	*p1 = NULL;
	char	*p2 = "World";

	int n11 = ft_printf("%c  %c", c1, c2);
	printf(" \n\n");
	int n12 = printf("%c  %c", c1, c2);
	printf(" \n\n");
	int n21 = ft_printf("%s  %s", s1, s2);
	printf(" \n\n");
	int n22 = printf("%s  %s", s1, s2);
	printf(" \n\n");
	int n31 = ft_printf("%p  %p", p1, p2);
	printf(" \n\n");
	int n32 = printf("%p  %p", p1, p2);
	printf(" \n\n");
	int n41 = ft_printf("%d  %i", d, i);
	printf(" \n\n");
	int n42 = printf("%d  %i", d, i);
	printf(" \n\n");
	int n51 = ft_printf("%u  %u", d, i);
	printf(" \n\n");
	int n52 = printf("%u  %u", d, i);
	printf(" \n\n");
	int n61 = ft_printf("%x  %x", d, i);
	printf(" \n\n");
	int n62 = printf("%x  %x", d, i);
	printf(" \n\n");
	int n71 = ft_printf("%X  %X", d, i);
	printf(" \n\n");
	int n72 = printf("%X  %X", d, i);
	printf(" \n\n");
	int n81 = ft_printf("%%  %%");
	printf(" \n\n");
	int n82 = printf("%%  %%");
	printf(" \n\n");
	printf("%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n%d %d\n", n11, n12, n21, n22, n31, n32, n41, n42, n51, n52, n61, n62, n71, n72, n81, n82);
	return (0);
}
