/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:43:34 by claudia           #+#    #+#             */
/*   Updated: 2025/03/13 18:39:41 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex_n	tricorn_iteration(t_complex_n z, t_complex_n c)
{
	t_complex_n	new_z;

	new_z.x = (z.x * z.x - z.y * z.y) + c.x;
	new_z.y = (-2 * z.x * z.y) + c.y;
	return (new_z);
}
