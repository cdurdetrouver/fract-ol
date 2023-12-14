/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:35:39 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/13 20:52:18 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	wronginputs(void)
{
	ft_printf("Usage: ./fractol [fractal] (optional)\n");
	ft_printf("Available fractals:\n");
	ft_printf("  - mandelbrot\n");
	ft_printf("  - julia (real) (imaginary)\n");
	ft_printf("  - burning_ship\n");
	exit(EXIT_FAILURE);
}

void	print_instructions(void)
{
	ft_printf("Instructions:\n");
	ft_printf("  - Move: arrows\n");
	ft_printf("  - Zoom: mouse wheel\n");
	ft_printf("  - Change color: +/-\n");
	ft_printf("  - Resolution: r\n");
	ft_printf("  - Reset: middle mouse boutton\n");
	ft_printf("  - Change fractal:\n\t  1: mandelbrot\n");
	ft_printf("\t  2: julia\n\t  3: burning_ship\n");
	ft_printf("  - Exit: esc\n");
}
