/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 15:49:58 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/27 13:36:40 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../ft_printf/Libft/libft.h"
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define KEY_ESC 65307
# define MOUSE_UP 4
# define MOUSE_DOWN 5
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

typedef struct s_complex
{
	double	re;
	double	im;
}	t_complex;

typedef struct s_image
{
	void		*img;
	void		*address;
	int			bpp;
	int			line_length;
	int			endian;
}	t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_image		img;

	t_complex	max;
	t_complex	min;
	t_complex	j;
	t_complex	c;
	t_complex	factor;

	double		max_iterations;
	char		*fractal_name;
	int			((*formula)(struct s_fractol *fractol));
}	t_fractol;
// Dimensions
# define WIDTH		1000
# define HEIGHT		1000
# define BPP
// Functions
int			ft_mandel(t_fractol *fractol);
int			ft_julia(t_fractol *fractol);
int			ft_burning(t_fractol *fractol);
void		my_pixel_put(t_fractol *fractol, int x, int y, int color);
void		set_value(t_fractol *fractol, double re, double im);
int			(*get_fractol(char *name))(t_fractol *fractol);
t_complex	create_complex(double re, double im);
void		ft_printexample(void);
void		draw(t_fractol *fractol);
void		ft_error(void);
int			ft_hook(int keysym, t_fractol *fractol);
int			zoom(int button, int x, int y, t_fractol *fractol);
int			close_window(t_fractol *fractol);
int			move(int keycode, t_fractol *fractol);
double		atod(char *num);
int			close_cross(void *param);
int			rainbow(int iterations, t_fractol *fractol);
int			blue(int iterations, t_fractol *fractol);

#endif
