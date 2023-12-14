/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:27:32 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/14 18:55:27 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	fractalrender(t_fractal *fractal)
{
	mlx_clear_window(fractal->mlx.mlx_ptr, fractal->mlx.win);
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		mandelbrotset(fractal);
	else if (!ft_strncmp(fractal->name, "julia", 5))
		juliaset(fractal);
	else if (!ft_strncmp(fractal->name, "burningship", 11))
		burningshipset(fractal);
	mlx_put_image_to_window(fractal->mlx.mlx_ptr, fractal->mlx.win,
		fractal->image.img, 0, 0);
}

void	init_mlx(t_mlx *mlx, t_image *image, char *name)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, name);
	image->img = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc >= 2)
	{
		set_params(&fractal, argc, argv);
		init_mlx(&fractal.mlx, &fractal.image, fractal.name);
		fractalrender(&fractal);
		print_instructions();
		mlx_key_hook(fractal.mlx.win, key_hook, &fractal);
		mlx_mouse_hook(fractal.mlx.win, mouse_click, &fractal);
		mlx_hook(fractal.mlx.win, 17, 1L << 17, close_window, &fractal);
		mlx_loop(fractal.mlx.mlx_ptr);
	}
	else
		wronginputs();
	return (0);
}
