/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:13:45 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/15 11:13:48 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

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
