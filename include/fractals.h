/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:18:55 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/15 12:19:01 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "vars.h"

double	julia(int x, int y, t_vars *vars);
double	mandelbrot(int x, int y, t_vars *vars);
double	burning_ship(int x, int y, t_vars *vars);

#endif
