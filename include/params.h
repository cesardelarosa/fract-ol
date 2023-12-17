/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:25:35 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/12/01 12:54:49 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARAMS_H
# define PARAMS_H

# define WIDTH 200
# define HEIGHT 200

# define ZOOM_FACTOR 1.15

typedef struct s_params
{
	void	*mlx;
	void	*win;
	double	x_move;
	double	y_move;
	double	zoom;
}	t_params;

#endif
