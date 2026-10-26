/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:54:05 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/26 16:36:57 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

int		ft_printf(const char *fmt, ...);
int		ft_putchar(int c);
int		ft_putbase(unsigned long n, const char *base);
int		ft_putnbr(long n);
int		ft_putptr(void *s);
int		ft_putstr(char *s);

#endif