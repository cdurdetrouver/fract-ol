/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:26:53 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/13 20:28:03 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	set_params_forall(t_fractal *fractal)
{
	fractal->min.x = -2.0;
	fractal->max.x = fractal->min.x * -1 * WIDTH / HEIGHT;
	fractal->min.y = -2;
	fractal->max.y = fractal->min.y * -1 * HEIGHT / WIDTH;
	fractal->iterations = 42;
	fractal->color = 0xccf1ff;
	fractal->escapevalue = 4;
}

void	set_params(t_fractal *fractal, int argc, char **argv)
{
	set_params_forall(fractal);
	if (!ft_strncmp(argv[1], "mandelbrot", 10) && ft_strlen(argv[1]) == 10
		&& argc == 2)
		fractal->name = "mandelbrot";
	else if (!ft_strncmp(argv[1], "julia", 5) && ft_strlen(argv[1]) == 5)
	{
		if (argc == 4)
			set_julia_complex_param(fractal, ft_atodbl(argv[2]),
				ft_atodbl(argv[3]));
		else if (argc == 2)
			set_julia_param(fractal);
		else
			wronginputs();
	}
	else if (!ft_strncmp(argv[1], "burningship", 11) && ft_strlen(argv[1]) == 11
		&& argc == 2)
		fractal->name = "burningship";
	else
		wronginputs();
}

void	set_julia_param(t_fractal *fractal)
{
	fractal->name = "julia";
	fractal->c.r = -0.7;
	fractal->c.i = 0.27015;
}

void	set_julia_complex_param(t_fractal *fractal, double r, double i)
{
	fractal->name = "julia";
	fractal->c.r = r;
	fractal->c.i = i;
}
