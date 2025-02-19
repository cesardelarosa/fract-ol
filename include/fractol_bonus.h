/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:04:15 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/02/19 17:04:24 by cde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# define WIDTH 600
# define HEIGHT 400
# define MAX_ITER 100
# define THRESHOLD 4.0

# define LEFT_CLICK 1 
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define C_KEY 99
# define R_KEY 114
# define CLOSE_WIN 17
# define ESC_KEY 65307
# define LEFT_ARROW_KEY 65361
# define UP_ARROW_KEY 65362
# define RIGHT_ARROW_KEY 65363
# define DOWN_ARROW_KEY 65364

# define X_VIEW 3.9
# define Y_VIEW 2.6

# define ZOOM_FACTOR 1.08
# define N_COLORS 15

# define FRACTALS "julia, mandelbrot"
# define FRACTALS2 "burning_ship, multibrot, tricorn, celtic, buffalo"

typedef struct s_pixel
{
	int			x;
	int			y;
}				t_pixel;

typedef struct s_complex
{
	double		x;
	double		y;
}				t_complex;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			bpp;
	int			sline;
	int			end;
	double		x;
	double		y;
	double		zoom;
	void		(*init_func)(t_pixel, struct s_vars*, t_complex*, t_complex*);
	void		(*update_func)(t_complex*, t_complex*, t_complex*);
	int			color;
	t_complex	julia;
}				t_vars;

typedef struct s_fractal
{
	const char	*name;
	void		(*init_func)(t_pixel, t_vars *, t_complex *, t_complex *);
	void		(*update_func)(t_complex *, t_complex *, t_complex *);
}	t_fractal;

void	cleanup(t_vars *vars);

void	init_julia(t_pixel p, t_vars *vars, t_complex *z, t_complex *c);
void	init_mandelbrot(t_pixel p, t_vars *vars, t_complex *z,
			t_complex *c);

void	update_standard(t_complex *z, t_complex *tmp, t_complex *c);

void	update_burning_ship(t_complex *z, t_complex *tmp, t_complex *c);
void	update_multibrot(t_complex *z, t_complex *tmp, t_complex *c);
void	update_tricorn(t_complex *z, t_complex *tmp, t_complex *c);
void	update_celtic(t_complex *z, t_complex *tmp, t_complex *c);
void	update_buffalo(t_complex *z, t_complex *tmp, t_complex *c);

void	draw(t_vars *vars);

int		key_hook(int keycode, t_vars *vars);
int		mouse_hook(int button, int x, int y, t_vars *vars);
int		close_window(t_vars *vars);

t_vars	parser(int argc, char **argv);

#endif
