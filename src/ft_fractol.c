/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:53:25 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/20 16:46:31 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	ft_mandel(t_fractol *fractol)
{
	int			iterations;
	t_complex	z;
	t_complex	tmp;

	iterations = 0;
	z = create_complex(fractol->c.re, fractol->c.im);
	tmp = create_complex(pow(z.re, 2), pow(z.im, 2));
	while (tmp.re + tmp.im < 4
		&& iterations < fractol->max_iterations)
	{
		z.im = z.re * z.im;
		z.im += z.im;
		z.im += fractol->c.im;
		z.re = tmp.re - tmp.im + fractol->c.re;
		tmp = create_complex(pow(z.re, 2), pow(z.im, 2));
		iterations++;
	}
	return (iterations);
}

int	ft_julia(t_fractol *fractol)
{
	int			iterations;
	t_complex	z;
	t_complex	tmp;

	iterations = 0;
	z = create_complex(fractol->c.re, fractol->c.im);
	tmp = create_complex(pow(z.re, 2), pow(z.im, 2));
	while (tmp.re + tmp.im <= 4
		&& iterations < fractol->max_iterations)
	{
		z.im = z.re * z.im;
		z.im += z.im;
		z.im += fractol->j.im;
		z.re = tmp.re - tmp.im + fractol->j.re;
		tmp = create_complex(pow(z.re, 2), pow(z.im, 2));
		iterations++;
	}
	return (iterations);
}

int	ft_burning(t_fractol *fractol)
{
	int			iterations;
	t_complex	z;
	t_complex	tmp;

	iterations = 0;
	z = create_complex(fractol->c.re, fractol->c.im);
	tmp = create_complex(pow(z.re, 2), pow(z.im, 2));
	while (tmp.re + tmp.im <= 4
		&& iterations < fractol->max_iterations)
	{
		z.im = -fabs(z.im * z.re);
		z.im += z.im;
		z.im += fractol->c.im;
		z.re = tmp.re - tmp.im + fractol->c.re;
		tmp = create_complex(pow(z.re, 2), pow(z.im, 2));
		iterations++;
	}
	return (iterations);
}
