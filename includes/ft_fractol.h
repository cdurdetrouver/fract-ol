/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:27:36 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/13 20:50:10 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define PLUS 65451
# define MINUS 65453
# define SPACE 32
# define WIDTH 800
# define HEIGHT 800
# define R 114

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

typedef struct s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct s_fractal
{
	t_complex	c;
	t_mlx		mlx;
	t_image		image;
	t_point		max;
	t_point		min;
	int			color;
	char		*name;
	int			iterations;
	double		escapevalue;
}				t_fractal;

// EVENT
int				mouse_scroll(int button, int x, int y, t_fractal *fractal);
int				key_release(int keycode, void *param);
int				mouse_click(int button, int x, int y, t_fractal *fractal);
int				key_press(int keycode, void *param);
int				close_window(void *param);
int				get_fractal(char *arg);
int				menu(void);
char			*print_fractal(int choice);
void			wronginputs(void);
void			print_instructions(void);
int				key_hook(int keycode, t_fractal *fractal);
void			set_params(t_fractal *fractal, int argc, char **argv);

// FRACTAL
void			mandelbrotset(t_fractal *mandel);
void			set_mandelbrot_param(t_fractal *fractal);
void			set_julia_param(t_fractal *fractal);
void			set_julia_complex_param(t_fractal *fractal, double r, double i);
void			juliaset(t_fractal *fractal);
void			burningshipset(t_fractal *fractal);
void			fractalrender(t_fractal *fractal);
void			my_mlx_pixel_put(t_image *image, t_point pos, int color);

// MATH
t_complex		sum(t_complex a, t_complex b);
t_complex		square_complex(t_complex a);
t_complex		square_complex_abs(t_complex a);

#endif
