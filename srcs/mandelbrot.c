/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 00:46:06 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/14 19:15:47 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	mandelbrot_pixel(t_point pos, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	t_complex	c;
	t_complex	last_z;

	i = 0;
	z.r = (fractal->min.x + pos.x * (fractal->max.x - fractal->min.x) / WIDTH);
	z.i = (fractal->max.y + pos.y * (fractal->min.y - fractal->max.y) / HEIGHT);
	c.r = z.r;
	c.i = z.i;
	while (i++ < fractal->iterations)
	{
		last_z = z;
		z = sum(square_complex(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractal->escapevalue)
			return (my_mlx_pixel_put(&fractal->image, pos, get_color(i,
						fractal->iterations)));
		if (i > 1 && last_z.r == z.r && last_z.i == z.i)
			break ;
	}
	my_mlx_pixel_put(&fractal->image, pos, 0x000000);
}

void	mandelbrotset(t_fractal *fractal)
{
	t_point	pos;

	pos.x = -1;
	while (++pos.x <= WIDTH)
	{
		pos.y = -1;
		while (++pos.y <= HEIGHT)
			mandelbrot_pixel(pos, fractal);
	}
}
