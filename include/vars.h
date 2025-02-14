/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 21:36:57 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/08 19:33:43 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# define WIDTH 500
# define HEIGHT 500

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		sline;
	int		end;
	double	x;
	double	y;
	double	zoom;
	int		(*fractal)(int x, int y, struct s_vars *vars);
	int		color;
	double	julia_cx;
	double	julia_cy;
}	t_vars;

#endif
