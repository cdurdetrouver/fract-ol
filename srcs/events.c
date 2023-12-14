/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbazart <gabriel.bazart@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:09:37 by gbazart           #+#    #+#             */
/*   Updated: 2023/12/14 16:45:27 by gbazart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fractol.h"

void	zoom(t_fractal *f, double zoom)
{
	t_point	center;

	center.x = f->min.x - f->max.x;
	center.y = f->max.y - f->min.y;
	f->max.x = f->max.x + (center.x - zoom * center.x) / 2;
	f->min.x = f->max.x + zoom * center.x;
	f->min.y = f->min.y + (center.y - zoom * center.y) / 2;
	f->max.y = f->min.y + zoom * center.y;
}

void	move(t_fractal *f, double distance, char dir)
{
	t_point	center;

	center.x = f->max.x - f->min.x;
	center.y = f->max.y - f->min.y;
	if (dir == 'R')
	{
		f->min.x += center.x * distance;
		f->max.x += center.x * distance;
	}
	else if (dir == 'L')
	{
		f->min.x -= center.x * distance;
		f->max.x -= center.x * distance;
	}
	else if (dir == 'D')
	{
		f->min.y -= center.y * distance;
		f->max.y -= center.y * distance;
	}
	else if (dir == 'U')
	{
		f->min.y += center.y * distance;
		f->max.y += center.y * distance;
	}
}

void	reset(t_fractal *fractal)
{
	fractal->min.x = -2.0;
	fractal->max.x = 2.0;
	fractal->min.y = -2.0;
	fractal->max.y = 2.0;
	fractal->iterations = 100;
	fractal->color = 0xccf1ff;
	fractal->escapevalue = 4;
}

int	mouse_click(int button, int x, int y, t_fractal *fractal)
{
	if (button == 2)
		reset(fractal);
	if (button == 5)
		zoom(fractal, 1.1);
	if (button == 4)
	{
		zoom(fractal, 0.9);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(fractal, (double)x * -1 / WIDTH, 'L');
		else if (x > 0)
			move(fractal, (double)x / WIDTH, 'R');
		if (y < 0)
			move(fractal, (double)y * -1 / HEIGHT, 'U');
		else if (y > 0)
			move(fractal, (double)y / HEIGHT, 'D');
	}
	fractalrender(fractal);
	return (0);
}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		close_window(fractal);
	else if (keycode == LEFT)
		move(fractal, 0.1, 'L');
	else if (keycode == DOWN)
		move(fractal, 0.1, 'D');
	else if (keycode == RIGHT)
		move(fractal, 0.1, 'R');
	else if (keycode == UP)
		move(fractal, 0.1, 'U');
	else if (keycode == PLUS)
		fractal->color += 100;
	else if (keycode == MINUS)
		fractal->color -= 100;
	else if (keycode == R)
		fractal->iterations += 10;
	if (keycode != ESC)
		fractalrender(fractal);
	return (0);
}
