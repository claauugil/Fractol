/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:46:05 by cgil              #+#    #+#             */
/*   Updated: 2025/03/14 16:12:32 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define WIDTH	800
# define HEIGHT	800
# define DARK_PINK 0xFFFFFF
# define YELLOW 0x000000
# define PURPLE 0x8A2BE2

typedef struct s_image
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_image;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_new_window;
	t_image	img;
	double	scape_value;
	int		iterations_def;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}		t_fractal;

typedef struct s_complex_n
{
	double	x;
	double	y;
}			t_complex_n;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			check_double(char *av);
void		print_error(void);
void		malloc_error(void);
void		fractal_init(t_fractal *fractal);
double		mapping(double unscaled_num, double new_min,
				double new_max, double old_max);
void		fractal_render(t_fractal *fractal);
t_complex_n	sum_complex(t_complex_n z1, t_complex_n z2);
t_complex_n	square_complex(t_complex_n z);
int			key_handler(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
double		ft_atodbl(char *s);
t_complex_n	tricorn_iteration(t_complex_n z, t_complex_n c);

#endif
