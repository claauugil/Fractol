/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42madrid.com>           #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 11:34:31 by cgil              #+#    #+#             */
/*   Updated: 2025-03-13 11:34:31 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int	check_double(char *av)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (!av || !*av)
		return (0);
	if (*av == '-' || *av == '+')
		i++;
	while (av[i])
	{
		if (av[i] == '.')
		{
			dot++;
			if (dot > 1)
				return (0);
		}
		else if (!ft_isdigit(av[i]))
			return (0);
		i++;
	}
	return (1);
}
