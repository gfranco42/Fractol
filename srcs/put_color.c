/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:04:36 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/07 17:42:08 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_color_inside(t_point point, int n, char *str)
{
	(void)n;
	str[(point.y * WIDTH + point.x) * 4] = 0x3A / n;
	str[(point.y * WIDTH + point.x) * 4 + 1] = 0xDF;
	str[(point.y * WIDTH + point.x) * 4 + 2] = 0x01;
}

void		put_color_outside(t_point point, int n, unsigned int *str)
{
	str[point.y * WIDTH + point.x] = 0x01DF3A / n;
}
