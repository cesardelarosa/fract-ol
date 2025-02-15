/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:13:07 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/15 11:13:25 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>

# include "vars.h"
# include "complex.h"
# include "hooks.h"
# include "parser.h"
# include "draw.h"

# define WIDTH 500
# define HEIGHT 500

# define MAX_ITER 100
# define THRESHOLD 3.0

# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define C_KEY 99
# define R_KEY 114
# define CLOSE_WIN 17
# define ESC_KEY 65307
# define LEFT_ARROW_KEY 65361
# define UP_ARROW_KEY 65362
# define RIGHT_ARROW_KEY 65363
# define DOWN_ARROW_KEY 65364

# define ZOOM_FACTOR 1.1
# define N_COLORS 10

#endif
