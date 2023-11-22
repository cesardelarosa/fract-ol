/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:36:08 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/22 03:43:28 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

t_complex	complex_sum(t_complex z1, t_complex z2)
{
	t_complex	sum;

	sum.x = z1.x + z2.x;
	sum.y = z1.y + z2.y;
	return (sum);
}

t_complex	complex_product(t_complex z1, t_complex z2)
{
	t_complex	product;

	product.x = z1.x * z2.x - z1.y * z2.y;
	product.y = z1.x * z2.y + z1.y * z2.x;
	return (product);
}

double	complex_norme(t_complex z)
{
	return (z.x * z.x + z.y * z.y);
}

t_complex	ft_julia(t_complex z, t_complex c)
{
	return (complex_sum(complex_product(z, z), c));
}

t_complex	ft_ship(t_complex z, t_complex c)
{
	t_complex	r;

	r.x = z.x * z.x - z.y * z.y;
	r.x = r.x * ((r.x > 0) - (r.x < 0)) + c.x;
	r.y = 2 * z.x * z.y;
	r.y = r.y * ((r.y > 0) - (r.y < 0)) + c.y;
	return (r);
}
