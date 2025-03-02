/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:06:41 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/02 18:04:49 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <math.h>

/*
 * update_burning_ship:
 *   Computes the Burning Ship fractal update.
 *   Formula:
 *     z = (|Re(z)|² - |Im(z)|²) + 2 · |Re(z)| · |Im(z)| · i + c
 */
void	update_burning_ship(t_complex *z, t_complex *tmp, t_complex *c)
{
	double	abs_re;
	double	abs_im;

	abs_re = fabs(tmp->x);
	abs_im = fabs(tmp->y);
	z->x = abs_re * abs_re - abs_im * abs_im + c->x;
	z->y = 2 * abs_re * abs_im + c->y;
}

/*
 * update_multibrot:
 *   Computes the Multibrot fractal update (n = 3) using polar coordinates.
 *   Formula:
 *     Let r = |z| and θ = arg(z)
 *     Then: z = r³ · exp(i · 3θ) + c
 *     That is:
 *       z.x = r³ · cos(3θ) + c.x
 *       z.y = r³ · sin(3θ) + c.y
 */
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
	r_d = r * r * r;
	theta_d = theta * n;
	z->x = r_d * cos(theta_d) + c->x;
	z->y = r_d * sin(theta_d) + c->y;
}

/*
 * update_tricorn:
 *   Computes the Tricorn fractal update.
 *   Formula:
 *     z = (conjugate(z))² + c
 *   In practice:
 *       z.x = Re(z)² - Im(z)² + c.x
 *       z.y = 2 · Re(z) · Im(z) + c.y
 */
void	update_tricorn(t_complex *z, t_complex *tmp, t_complex *c)
{
	double	re;
	double	im;

	re = tmp->x;
	im = -tmp->y;
	z->x = re * re - im * im + c->x;
	z->y = 2 * re * im + c->y;
}

/*
 * update_celtic:
 *   Computes the Celtic fractal update.
 *   Formula:
 *     z = |Re(z)² - Im(z)²| + c.x  +  i · (2 · Re(z) · Im(z) + c.y)
 */
void	update_celtic(t_complex *z, t_complex *tmp, t_complex *c)
{
	double	diff;

	diff = tmp->x * tmp->x - tmp->y * tmp->y;
	z->x = fabs(diff) + c->x;
	z->y = 2 * tmp->x * tmp->y + c->y;
}

/*
 * update_buffalo:
 *   Computes the Buffalo fractal update.
 *   Formula:
 *     z = (|Re(z)|² - |Im(z)|² - |Re(z)| + c.x) +
 *         i · (2 · |Re(z)| · |Im(z)| - |Im(z)| + c.y)
 */
void	update_buffalo(t_complex *z, t_complex *tmp, t_complex *c)
{
	double	abs_re;
	double	abs_im;

	abs_re = fabs(tmp->x);
	abs_im = fabs(tmp->y);
	z->x = abs_re * abs_re - abs_im * abs_im - abs_re + c->x;
	z->y = 2 * abs_re * abs_im - abs_im + c->y;
}
