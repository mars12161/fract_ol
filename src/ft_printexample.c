/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printexample.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:37:32 by mschaub           #+#    #+#             */
/*   Updated: 2023/03/20 15:43:57 by mschaub          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	ft_printexample(void)
{
	ft_printf("How to run the program: ./fract-ol \"name of set\"\n");
	ft_printf("These are the possible fractals: \n");
	ft_printf("Mandelbrot -> to create the Mandelbrot Set");
	ft_printf(" please enter 'Mandelbrot'\n");
	ft_printf("Julia -> to create the Julia Set please enter 'Julia'\n");
	ft_printf("To modify the Julia Set you can add an imaginary number\n");
	ft_printf("Please enter the number like this: ");
	ft_printf("Julia <realPart> <imaginaryPart>\n");
	ft_printf("Some examples are:");
	ft_printf(" 'Julia -0.61 0'; 'Julia 0 -0.8'; Julia -0.8 0.156\n");
	exit(0);
}
