/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 02:53:55 by cde-la-r          #+#    #+#             */
/*   Updated: 2024/10/31 03:07:45 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include "vars.h"


int		julia(int x, int y, t_vars *vars);
int		mandelbrot(int x, int y, t_vars *vars);
int		burning_ship(int x, int y, t_vars *vars);
void	draw_bonus(t_vars *vars);
int		(*select_fractal_bonus(char *str))(int x, int y, t_vars *vars);

#endif
