/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:39:22 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/09/29 03:11:50 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr(long n);
int	ft_puthex(unsigned long n, int up);
int	ft_putptr(void *ptr);
int	ft_format(const char format, va_list args);
int	ft_printf(const char *str, ...);

#endif
