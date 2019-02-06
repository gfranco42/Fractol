/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:04:36 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/06 13:10:41 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_color_black(t_point point, int n, char *str)
{
	n = 0;
	str[(point.x + point.y * WIDTH) * 4] = 0;
	str[(point.x + point.y * WIDTH) * 4 + 1] = 0;
	str[(point.x + point.y * WIDTH) * 4 + 2] = 0;
	str[(point.x + point.y * WIDTH) * 4 + 3] = 0;
}

void		put_color_white(t_point point, int n, char *str)
{
	n = 0;
	str[(point.x + point.y * WIDTH) * 4] = 0xff;
	str[(point.x + point.y * WIDTH) * 4 + 1] = 0xff;
	str[(point.x + point.y * WIDTH) * 4 + 2] = 0xff;
	str[(point.x + point.y * WIDTH) * 4 + 3] = 0;
}
