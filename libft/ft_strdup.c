/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 14:32:56 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/09/19 19:43:56 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*r;
	size_t	l;

	l = ft_strlen(s);
	r = (char *)malloc((l + 1) * sizeof(char));
	if (!r)
		return (NULL);
	ft_strlcpy(r, s, l + 1);
	return (r);
}
