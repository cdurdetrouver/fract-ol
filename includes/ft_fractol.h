/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:27:36 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/09 02:44:20 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_complex
{
	double		r;
	double		i;
}				t_complex;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win;
	void		*img;
	int			width;
	int			height;
}				t_mlx;

typedef struct s_fractal
{
	t_complex	c;
	double		zoom;
	double		x;
	double		y;
	double		xarrow;
	double		yarrow;
	double		radius;
	int			iterations;
	int			color;
	int			*(*func[3])(struct s_fractal *);
}				t_fractal;

typedef struct s_rgba
{
	uint8_t		b;
	uint8_t		g;
	uint8_t		r;
	uint8_t		a;
}				t_rgba;

// EVENT
int				mouse_scroll(int button, int x, int y, void *param);
int				key_release(int keycode, void *param);
int				mouse_move(int x, int y, void *param);
int				key_press(int keycode, void *param);
int				close_window(void *param);
int				get_fractal(char *arg);
int				menu(void);
char			*print_fractal(int choice);
void			set_hooks(t_mlx *mlx);

// FRACTAL
void			*mandelbrotset(t_fractal *mandel);

// COLOR
int				*color_gradient(int start, int end, int size);
int				rgb_gradient(int start, int end, double percent);
int				hex_to_rgb(int hex, int rgb);
int				rgb_to_hex(int r, int g, int b);

#endif
