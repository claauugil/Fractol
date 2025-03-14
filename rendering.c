/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:28:51 by claudia           #+#    #+#             */
/*   Updated: 2025/03/14 12:28:47 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_image *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_julia(t_complex_n *z, t_complex_n *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex_n	z;
	t_complex_n	c;
	int			i;
	int			color;

	i = 0;
	z.x = (mapping(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (mapping(y, -2, +2, HEIGHT) * fractal->zoom) + fractal->shift_y;

	if (!ft_strncmp(fractal->name, "burningship", 11))
		c = z;
	else
		mandel_julia(&z, &c, fractal);

	while (i < fractal->iterations_def)
	{
		if (!ft_strncmp(fractal->name, "burningship", 11))
			z = burning_ship_iteration(z, c);
		else
			z = sum_complex(square_complex(z), c);

		if ((z.x * z.x) + (z.y * z.y) > fractal->scape_value)
		{
			color = mapping(i, DARK_PINK, YELLOW, fractal->iterations_def);
			my_pixel_put(x, y, &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(x, y, &fractal->img, PURPLE);
}

t_complex_n	burning_ship_iteration(t_complex_n z, t_complex_n c)
{
	t_complex_n	new_z;

	new_z.x = (z.x * z.x) - (z.y * z.y) + c.x;
    new_z.y = (2 * fabs(z.x) * fabs(z.y)) + c.y;
	return (new_z);
}

/*
static int	compute_fractal(t_complex_n z, t_fractal *fractal)
{
	t_complex_n	c;
	int			i;

	i = 0;
	if (!ft_strncmp(fractal->name, "tricorn", 7))
		c = z;
	else
		mandel_julia(&z, &c, fractal);
	while (i < fractal->iterations_def)
	{
		if (!ft_strncmp(fractal->name, "tricorn", 7))
			z = tricorn_iteration(z, c);
		else
			z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->scape_value)
			return (i);
		i++;
	}
	return (i);
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex_n	z;
	int			iterations;
	int			color;

	z.x = (mapping(x, -2, +2, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (mapping(y, +2, -2, HEIGHT) * fractal->zoom) + fractal->shift_y;
	iterations = compute_fractal(z, fractal);
	if (iterations < fractal->iterations_def)
		color = mapping(iterations, DARK_PINK, YELLOW, fractal->iterations_def);
	else
		color = PURPLE;
	my_pixel_put(x, y, &fractal->img, color);
}*/

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_new_window,
		fractal->img.img_ptr, 0, 0);
}
