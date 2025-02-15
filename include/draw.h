/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:15:08 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/15 11:24:56 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "fractol.h"

int		julia(int x, int y, t_vars *vars);
int		mandelbrot(int x, int y, t_vars *vars);
int		burning_ship(int x, int y, t_vars *vars);

void	draw(t_vars *vars);

#endif
