/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:04:36 by gfranco           #+#    #+#             */
/*   Updated: 2019/03/04 16:48:16 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_color_inside(t_point point, int n, unsigned int *str)
{
	str[point.y * WIDTH + point.x] = 0 / n;
}

void		put_color_outside(t_point point, int n, unsigned int *str)
{
	str[point.y * WIDTH + point.x] = 0x01DF3A / n;
}
