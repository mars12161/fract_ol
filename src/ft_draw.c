/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:46:12 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/20 16:51:18 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	draw(t_fractol *fractol)
{
	int	x;
	int	y;	
	int	color;

	fractol->factor = create_complex((fractol->max.re - fractol->min.re)
			/ WIDTH, (fractol->max.im - fractol->min.im) / HEIGHT);
	y = 0;
	while (y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = blue(fractol->formula(fractol), fractol);
			my_pixel_put(fractol, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}
