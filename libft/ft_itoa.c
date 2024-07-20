/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 09:10:03 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/08/16 19:41:52 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				l;
	unsigned int	num;
	char			*r;

	l = (n == 0);
	num = n * (n >= 0) - n * (n < 0);
	while (num)
	{
		l++;
		num /= 10;
	}
	r = (char *)malloc((l + (n < 0) + 1) * sizeof(char));
	if (!r)
		return (NULL);
	if (n < 0)
		r[0] = '-';
	num = n * (n >= 0) - n * (n < 0);
	r[l + (n < 0)] = '\0';
	while (l--)
	{
		r[l + (n < 0)] = '0' + (num % 10);
		num /= 10;
	}
	return (r);
}
