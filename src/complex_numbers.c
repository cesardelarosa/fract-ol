/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:36:08 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/18 10:49:17 by cde-la-r         ###   ########.fr       */
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
