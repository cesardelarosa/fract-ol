/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:05:56 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/03/02 18:28:33 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "libft.h"
#include "mlx.h"
#include <stdlib.h>

static void	fill_info_panel(t_vars *vars)
{
	t_pixel	p;

	p.y = HEIGHT - 1;
	while (++p.y < HEIGHT + INFO_HEIGHT)
	{
		p.x = -1;
		while (++p.x < WIDTH)
			mlx_pixel_put(vars->mlx, vars->win, p.x, p.y, 0x000000);
	}
}

static char	*build_fractal_line_bonus(t_vars *vars)
{
	if (vars->fractal.init_func == init_julia)
		return (ft_strjoin((char *)vars->fractal.name, " (julia type)"));
	else if (vars->fractal.init_func == init_mandelbrot)
		return (ft_strjoin((char *)vars->fractal.name, " (mandelbrot type)"));
	return (ft_strdup("unknown"));
}

static char	*build_fractal_line_nonbonus(t_vars *vars)
{
	if (vars->fractal.init_func == init_julia)
		return (ft_strdup("julia"));
	else if (vars->fractal.init_func == init_mandelbrot)
		return (ft_strdup("mandelbrot"));
	return (ft_strdup("unknown"));
}

static char	*build_complex_str(t_complex comp)
{
	char	*real_str;
	char	*imag_str;
	char	*result;
	char	*tmp;

	real_str = ft_ftoa(comp.x, 4);
	imag_str = ft_ftoa(comp.y, 4);
	if (imag_str[0] == '-')
	{
		tmp = ft_strjoin(real_str, " - ");
		result = ft_strjoin(tmp, ft_strdup(imag_str + 1));
		free(tmp);
	}
	else
	{
		tmp = ft_strjoin(real_str, " + ");
		result = ft_strjoin(tmp, imag_str);
		free(tmp);
	}
	tmp = ft_strjoin(result, "i");
	free(result);
	free(real_str);
	free(imag_str);
	return (tmp);
}

void	display_info(t_vars *vars)
{
	char	*line;

	fill_info_panel(vars);
	if (vars->fractal.is_bonus == 1)
		line = build_fractal_line_bonus(vars);
	else
		line = build_fractal_line_nonbonus(vars);
	mlx_string_put(vars->mlx, vars->win, 10, HEIGHT + 20, 0xFFFFFF, line);
	free(line);
	if (vars->fractal.init_func == init_julia)
	{
		mlx_string_put(vars->mlx, vars->win, 10, HEIGHT + 40, 0xFFFFFF,
			build_complex_str(vars->julia));
	}
	vars->info_update = 0;
}
