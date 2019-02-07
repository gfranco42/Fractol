/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:04:36 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/07 17:54:35 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void		put_color_inside(t_point point, int n, char *str, int degrade)
{
	(void)n;
	(void)degrade;
	str[(point.x + point.y * WIDTH) * 4] = point.x / 2;
	str[(point.x + point.y * WIDTH) * 4 + 1] = 0;
	str[(point.x + point.y * WIDTH) * 4 + 2] = point.x / 2;
	str[(point.x + point.y * WIDTH) * 4 + 3] = 0;
}

void		put_color_outside(t_point point, int n, char *str, int degrade)
{
	(void)n;
	(void)degrade;
	str[(point.x + point.y * WIDTH) * 4] = n;
	str[(point.x + point.y * WIDTH) * 4 + 1] = 0;
	str[(point.x + point.y * WIDTH) * 4 + 2] = n / 2;
	str[(point.x + point.y * WIDTH) * 4 + 3] = 0;
}
