/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:37:08 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/09/04 16:29:17 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "vars.h"

void	draw(t_vars *vars);
int	(*select_fractal(char *str))(int x, int y, t_vars *vars);
double	ft_atof(const char *str);

#endif
