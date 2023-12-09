/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:27:32 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/09 02:45:25 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	set_hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx->win, key_press, mlx);
	mlx_hook(mlx->win, 2, 1L << 0, key_press, mlx);
	mlx_hook(mlx->win, 3, 1L << 1, key_release, mlx);
	mlx_hook(mlx->win, 17, 1L << 17, close_window, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, mouse_scroll, mlx);
	mlx_hook(mlx->win, 6, 1L << 6, mouse_move, mlx);
}

static t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx_ptr, 800, 800, "Fractol");
	mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	return (mlx);
}

void	createfractal(t_mlx *mlx, t_fractal *fractal, int fractal_number)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	mlx->addr = mlx_get_data_addr(mlx->mlx_ptr, fractal->bits_per_pixel,
			fractal->line_length, fractal->endian);
	fractal->func[fractal_number](fractal);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win, mlx->img, 0, 0);
}

int	main(int argc, char **argv)
{
	int			fractal_number;
	t_mlx		*mlx;
	t_fractal	fractal;

	fractal_number = 0;
	if (argc == 1)
		fractal_number = menu();
	else if (argc == 2)
		fractal_number = get_fractal(argv[1]);
	if (fractal_number == 0)
	{
		ft_printf("Choix non valide.\n");
		fractal_number = menu();
	}
	ft_printf("\nVous avez choisi :  %s\n", print_fractal(fractal_number));
	mlx->mlx = init_mlx();
	fractal.func[0] = NULL;
	fractal.func[1] = mandelbrotset;
	fractal.func[2] = julia;
	createfractal(mlx, &fractal, fractal_number);
	set_hooks(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (0);
}
