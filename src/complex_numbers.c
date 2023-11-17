/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:36:08 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/17 20:43:47 by cde-la-r         ###   ########.fr       */
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

t_complex	complex_pow(t_complex z, unsigned int n)
{
	t_complex	squared;

	if (n == 0)
		return ((t_complex){1, 0});
	if (n == 1)
		return (z);
	squared.x = z.x * z.x - z.y * z.y;
	squared.y = 2 * z.x * z.y;
	return (complex_pow(squared, n - 1));
}

double	complex_norme(t_complex z)
{
	return (z.x * z.x + z.y * z.y);
}

t_complex	ft_julia(t_complex z, t_complex c)
{
	return (complex_sum(complex_pow(z, 2), c));
}
