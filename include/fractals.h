/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:18:55 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/17 17:12:18 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

# include "vars.h"

double	julia(t_pixel p, t_vars *vars);
double	mandelbrot(t_pixel p, t_vars *vars);
double	burning_ship(t_pixel p, t_vars *vars);

#endif
