/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 19:47:09 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/13 20:22:03 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	burningship_pixel(t_point pos, t_fractal *fractal)
{
	int			i;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.r = (fractal->min.x + pos.x * (fractal->max.x - fractal->min.x) / WIDTH);
	z.i = -(fractal->max.y + pos.y * (fractal->min.y - fractal->max.y)
			/ HEIGHT);
	c.r = z.r;
	c.i = z.i;
	while (i++ < fractal->iterations)
	{
		z = sum(square_complex_abs(z), c);
		if ((z.r * z.r) + (z.i * z.i) > fractal->escapevalue)
		{
			my_mlx_pixel_put(&fractal->image, pos, fractal->color * i);
			break ;
		}
	}
}

void	burningshipset(t_fractal *fractal)
{
	t_point	pos;

	pos.x = -1;
	while (++pos.x <= WIDTH)
	{
		pos.y = -1;
		while (++pos.y <= HEIGHT)
			burningship_pixel(pos, fractal);
	}
}
