/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:18:55 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/17 17:20:15 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H

# include "vars.h"

void	init_julia(t_pixel p, t_vars *vars, t_complex *z, t_complex *c);
void	init_mandelbrot(t_pixel p, t_vars *vars, t_complex *z, t_complex *c);
void	update_standard(t_complex *z, t_complex *tmp, t_complex *c);
void	update_burning_ship(t_complex *z, t_complex *tmp, t_complex *c);
double	calc_fractal(t_pixel p, t_vars *vars, void (*init_func)(t_pixel,
				t_vars *, t_complex *, t_complex *),
			void (*update_func)(t_complex *, t_complex *, t_complex *));

#endif
