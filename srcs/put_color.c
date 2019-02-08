/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:04:36 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/08 16:06:42 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_color_inside(t_point point, int n, char *str, t_mlx mlx)
{
	(void)n;
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;
	unsigned long img_color;

	img_color = mlx_get_color_value(mlx.ptr, 0xf8f8ff);

	color1 = (img_color & 0xFF00000) >> 24;
	color2 = (img_color & 0xFF00000) >> 16;
	color3 = (img_color & 0xFF00000) >> 8;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8] = color1;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 1] = color2;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 2] = color3;
}

void		put_color_outside(t_point point, int n, char *str, t_mlx mlx)
{
	(void)n;
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;
	unsigned long img_color;

	img_color = mlx_get_color_value(mlx.ptr, 0xf8f8ff);

	color1 = (img_color & 0xFF00000) >> 24;
	color2 = (img_color & 0xFF00000) >> 16;
	color3 = (img_color & 0xFF00000) >> 8;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8] = color1;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 1] = color2;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 2] = color3;
}
