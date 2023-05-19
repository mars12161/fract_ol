/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:55:09 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/27 13:54:39 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	(*get_fractol(char *name)) (t_fractol *fractol)
{
	if (!ft_strncmp(name, "Mandelbrot", ft_strlen(name) + 1))
		return (&ft_mandel);
	else if (!ft_strncmp(name, "Julia", ft_strlen(name) + 1))
		return (&ft_julia);
	else if (!ft_strncmp(name, "Burning Ship", ft_strlen(name) + 1))
		return (&ft_burning);
	else
		return (0);
}

/* 
set values for the max and min values of the fractal
 */

void	set_value(t_fractol *fractol, double re, double im)
{
	fractol->max_iterations = 50;
	fractol->min = create_complex(-2.0, -2.0);
	fractol->max.im = 2.0;
	fractol->max.re = fractol->min.re + (fractol->max.im - fractol->min.im)
		* WIDTH / HEIGHT;
	fractol->j = create_complex(re, im);
}

/*
mlx_init() initialisiert eine window-instance
mlx_new_window erstellt das eigentliche Fenster
mlx_get_data_addr initialisiert die bpp, die line_length und den endian 
 */

void	create_fractal(t_fractol *fractol, char *name, double re, double im)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		ft_error();
	fractol->win = mlx_new_window(fractol->mlx, WIDTH, HEIGHT, name);
	if (!fractol->win)
		ft_error();
	fractol->img.img = mlx_new_image(fractol->mlx, WIDTH, HEIGHT);
	if (!fractol->img.img)
		ft_error();
	fractol->img.address = mlx_get_data_addr(fractol->img.img,
			&(fractol->img.bpp), &(fractol->img.line_length),
			&(fractol->img.endian));
	set_value(fractol, re, im);
	fractol->formula = get_fractol(name);
	mlx_hook(fractol->win, KeyPress, KeyPressMask, *ft_hook, &fractol);
	mlx_hook(fractol->win, 17, 0L, close_window, &fractol);
	mlx_mouse_hook(fractol->win, zoom, fractol);
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	if (argc != 2 && argc != 4)
		ft_printexample();
	if (argc == 2 && get_fractol(argv[1]))
	{
		create_fractal(&fractol, argv[1], -0.4, 0.6);
		draw(&fractol);
		mlx_loop(fractol.mlx);
	}
	else if (argc == 4 && get_fractol(argv[1]))
	{
		create_fractal(&fractol, argv[1], atod(argv[2]), atod(argv[3]));
		draw(&fractol);
		mlx_loop(fractol.mlx);
	}
	return (0);
}
