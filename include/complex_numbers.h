/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_numbers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:41:42 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/22 03:07:50 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_NUMBERS_H
# define COMPLEX_NUMBERS_H

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

t_complex	complex_sum(t_complex z1, t_complex z2);
t_complex	complex_product(t_complex z1, t_complex z2);
double		complex_norme(t_complex z);
t_complex	ft_julia(t_complex z, t_complex c);
t_complex	ft_ship(t_complex z, t_complex c);

#endif
