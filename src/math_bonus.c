/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:14:34 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/19 13:02:41 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void	update_burning_ship(t_complex *z, t_complex *tmp, t_complex *c)
{
	double	abs_re;
	double	abs_im;

	abs_re = fabs(tmp->x);
	abs_im = fabs(tmp->y);
	z->x = abs_re * abs_re - abs_im * abs_im + c->x;
	z->y = 2 * abs_re * abs_im + c->y;
}

void	update_multibrot(t_complex *z, t_complex *tmp, t_complex *c)
{
	int		n;
	double	r;
	double	theta;
	double	r_d;
	double	theta_d;

	n = 3;
	r = sqrt(tmp->x * tmp->x + tmp->y * tmp->y);
	theta = atan2(tmp->y, tmp->x);
	r_d = pow(r, n);
	theta_d = theta * n;
	z->x = r_d * cos(theta_d) + c->x;
	z->y = r_d * sin(theta_d) + c->y;
}

void	update_tricorn(t_complex *z, t_complex *tmp, t_complex *c)
{
	double	re;
	double	im;

	re = tmp->x;
	im = -tmp->y;
	z->x = re * re - im * im + c->x;
	z->y = 2 * re * im + c->y;
}

void	update_celtic(t_complex *z, t_complex *tmp, t_complex *c)
{
	double	diff;

	diff = tmp->x * tmp->x - tmp->y * tmp->y;
	z->x = fabs(diff) + c->x;
	z->y = 2 * tmp->x * tmp->y + c->y;
}

void	update_buffalo(t_complex *z, t_complex *tmp, t_complex *c)
{
	double	abs_re;
	double	abs_im;

	abs_re = fabs(tmp->x);
	abs_im = fabs(tmp->y);
	z->x = abs_re * abs_re - abs_im * abs_im - abs_re + c->x;
	z->y = 2 * abs_re * abs_im - abs_im + c->y;
}
