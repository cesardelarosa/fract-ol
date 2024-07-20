/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:52:20 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/08/16 17:43:54 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	d_len;
	size_t	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (d_len >= n)
		return (s_len + n);
	if (d_len + s_len < n)
		ft_memcpy(dest + d_len, src, s_len + 1);
	else
	{
		ft_memcpy(dest + d_len, src, n - d_len - 1);
		dest[n - 1] = '\0';
	}
	return (d_len + s_len);
}
