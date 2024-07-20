/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 12:32:54 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/09/19 19:30:02 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t	l;

	l = ft_strlen(substr);
	if (l == 0)
		return ((char *)str);
	while (*str && n-- >= l)
	{
		if (!ft_strncmp(str, substr, l))
			return ((char *)str);
		str++;
	}
	return (NULL);
}
