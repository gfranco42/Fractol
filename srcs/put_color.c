/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:04:36 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/12 16:29:49 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_color_inside(t_point point, int n, unsigned int *str, t_mlx mlx)
{
	(void)n;
	(void)mlx;

	str[point.y * WIDTH + point.x] = 0x0379EF;
	/*str[point.y * mlx.s_l + point.x * mlx.bpp / 8] = 0x03;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 1] = 0x79;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 2] = 0xEF;*/
}

void		put_color_outside(t_point point, int n, char *str, t_mlx mlx)
{
	(void)n;

	str[point.y * mlx.s_l + point.x * mlx.bpp / 8] = 0;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 1] = 0;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 2] = 0;
}
