/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:54:37 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/20 16:53:33 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	blue(int iterations, t_fractol *fractol)
{
	int	color;
	int	i;

	(void)fractol;
	i = iterations;
	color = (unsigned char)(sin(0.3 * (double)i));
	color <<= 8;
	color += (unsigned char)(sin(0.3 * (double)i + 3.0) * 127.0 + 128.0);
	color <<= 8;
	color += (unsigned char)(sin(0.3 * (double)i + 3.0) * 127.0 + 128.0);
	return (color);
}
