/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:58:59 by claudia           #+#    #+#             */
/*   Updated: 2025/03/14 12:02:29 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_new_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations_def += 10;
	else if (keysym == XK_minus)
		fractal->iterations_def -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double	prev_zoom;
	double	new_zoom;
	double	complex_x;
	double	complex_y;

	prev_zoom = fractal->zoom;
	if (button == Button5)
		new_zoom = fractal->zoom * 0.95;
	else if (button == Button4)
		new_zoom = fractal->zoom * 1.05;
	else
		return (0);
	complex_x = (mapping(x, -2, +2, WIDTH) * prev_zoom) + fractal->shift_x;
	complex_y = (mapping(y, +2, -2, HEIGHT) * prev_zoom) + fractal->shift_y;
	fractal->shift_x += (complex_x - ((mapping(x, -2, +2, WIDTH) * new_zoom)
				+ fractal->shift_x));
	fractal->shift_y += (complex_y - ((mapping(y, +2, -2, HEIGHT) * new_zoom)
				+ fractal->shift_y));
	fractal->zoom = new_zoom;
	fractal_render(fractal);
	return (0);
}
