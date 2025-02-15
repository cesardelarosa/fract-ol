/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:14:22 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/15 11:14:23 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "fractol.h"

int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		close_window(t_vars *vars);

#endif
