/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:17:58 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/27 13:49:40 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	ft_hook(int keysym, t_fractol *fractol)
{
	if (keysym == KEY_ESC)
		close_window(fractol);
	return (0);
}

int	close_window(t_fractol *fractol)
{
	(void) fractol;
	exit(0);
}

static double	interpol(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

int	zoom(int button, int x, int y, t_fractol *fractol)
{
	t_complex	mouse;
	double		zoom;

	if (button == MOUSE_UP || button == MOUSE_DOWN)
	{
		mouse = create_complex((double)x / (WIDTH
					/ (fractol->max.re - fractol->min.re))
				+ fractol->min.re,
				(double)y / (HEIGHT
					/ (fractol->max.im - fractol->min.im))
				* -1 + fractol->max.im);
		if (button == MOUSE_UP)
			zoom = 0.80;
		else
			zoom = 1.20;
		fractol->min.re = interpol(mouse.re, fractol->min.re, zoom);
		fractol->min.im = interpol(mouse.im, fractol->min.im, zoom);
		fractol->max.re = interpol(mouse.re, fractol->max.re, zoom);
		fractol->max.im = interpol(mouse.im, fractol->max.im, zoom);
		draw(fractol);
	}
	return (0);
}
