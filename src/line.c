/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:59:59 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/13 22:49:35 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_math.h"

t_bshm_line		line_init(t_point3d p1, t_point3d p2)
{
	int				tmp;
	t_bshm_line		line;

	line.p1 = p1;
	line.p2 = p2;
	line.dx = (int)ABS(p1.x - p2.x);
	line.dy = (int)ABS(p1.y - p2.y);
	line.sx = 1;
	line.sy = 1;
	line.dx = ABS(POINTDXINT(p2, p1));
	line.dy = ABS(POINTDYINT(p2, p1));
	line.sx = SIGN(POINTDXINT(p2, p1));
	line.sy = SIGN(POINTDYINT(p2, p1));
	line.change = 0;
	if (line.dy > line.dx)
		SWAP(line.dx, line.dy, tmp) && (line.change = 1);
	line.er = 2 * line.dy - line.dx;
	return (line);
}
