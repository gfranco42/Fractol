/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:04:36 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/11 13:22:14 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_color_inside(t_point point, int n, char *str, t_mlx mlx)
{
	(void)n;

	str[point.y * mlx.s_l + point.x * mlx.bpp / 8] = 0x03;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 1] = 0x79;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 2] = 0xEF;
}

void		put_color_outside(t_point point, int n, char *str, t_mlx mlx)
{
	(void)n;

	str[point.y * mlx.s_l + point.x * mlx.bpp / 8] = 0;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 1] = 0;
	str[point.y * mlx.s_l + point.x * mlx.bpp / 8 + 2] = 0;
}
