/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <cde-la-r@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 07:47:58 by cde-la-r          #+#    #+#             */
/*   Updated: 2023/11/18 11:14:48 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include "params.h"
#include "hooks.h"
#include "draw.h"

int	main(void)
{
	t_params	params;

	params.mlx = mlx_init();
	params.win = mlx_new_window(params.mlx, WIDTH, HEIGHT, "fract-ol");
	params.x_move = 0.0;
	params.y_move = 0.0;
	params.zoom = 1.0;
	mlx_key_hook(params.win, key_hook, &params);
	mlx_hook(params.win, CLOSE_WIN, 0, close_window_hook, &params);
	mlx_mouse_hook(params.win, mouse_hook, &params);
	draw_julia_set(&params);
	mlx_loop(params.mlx);
	return (0);
}
