/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:59:59 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/10 21:18:53 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_math.h"

t_bshm_line		line_init(t_point3d p1, t_point3d p2)
{
	t_bshm_line		line;

	line.s = p1;
	line.e = p2;
	line.dx = (int)ABS(p1.x - p2.x);
	line.dy = (int)ABS(p1.y - p2.y);
	line.sx = 1;
	line.sy = 1;
	line.derr = ABS(line.dy - line.dx);
	line.err = 0.5;
	return (line);
}
