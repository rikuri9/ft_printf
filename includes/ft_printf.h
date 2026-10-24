/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riwamoto <riwamoto@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 13:54:05 by riwamoto          #+#    #+#             */
/*   Updated: 2026/10/24 12:02:30 by riwamoto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *fmt, ...);
int		ft_putchar(char c);
int		ft_putbase(unsigned long n, const char *base);
int		ft_putnbr(long n);
int		ft_putptr(char *s);
int		ft_putstr(char *s);

#endif