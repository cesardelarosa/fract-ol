/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 01:39:09 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/09/29 03:11:48 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(const char *str)
{
	int	len;

	if (!str)
		return (ft_putstr("(null)"));
	len = 0;
	while (str[len])
		len += ft_putchar(str[len]);
	return (len);
}

int	ft_putnbr(long n)
{
	int	len;

	len = 0;
	if (n > 9 || n < -9)
		len += ft_putnbr(n / 10);
	else if (n < 0)
		len += ft_putchar('-');
	len += ft_putchar('0' + n % 10 * ((n > 0) - (n < 0)));
	return (len);
}

int	ft_puthex(unsigned long n, int up)
{
	int		len;
	char	*base;

	len = 0;
	if (n > 15)
		len += ft_puthex(n / 16, up);
	base = "0123456789abcdef";
	len += ft_putchar(base[n % 16] + up * (('A' - 'a') * (n % 16 > 9)));
	return (len);
}

int	ft_putptr(void *ptr)
{
	return (ft_putstr("0x") + ft_puthex((unsigned long)ptr, 0));
}
