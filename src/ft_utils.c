/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:54:32 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/26 13:13:50 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	ft_error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(0);
}

void	my_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	char	*dest;

	dest = fractol->img.address + (y * fractol->img.line_length
			+ x * (fractol->img.bpp / 8));
	*(unsigned int *)dest = color;
}

static double	returnnegative(int neg, double a)
{
	if (neg == 1)
		return (-a);
	else
		return (a);
}

static double	loops(char *num, int dot, double value, double scale)
{
	while (*num)
	{
		if (dot)
		{
			scale = scale / 10;
			value = value + (*num - '0') * scale;
		}
		else
		{
			if (*num == '.')
				dot++;
			else
				value = value * 10.0 + (*num - '0');
		}
		num++;
	}
	return (value);
}

double	atod(char *num)
{
	double	value;
	int		dot;
	int		neg;
	double	scale;

	value = 0;
	scale = 1;
	neg = 0;
	dot = 0;
	if (*num == '-')
	{
		num++;
		neg = 1;
	}
	value = loops(num, dot, value, scale);
	return (returnnegative(neg, value));
}
