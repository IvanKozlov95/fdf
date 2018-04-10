/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:04:31 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/09 22:13:03 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void		iterate_points(t_map *map, void (*f)(t_map *, int, int))
{
	int		i;
	int		size;

	i = -1;
	size = map->height * map->width;
	while (++i < size)
		f(map, i % map->width, i / map->height);
}

/*
**
**function line(x0, y0, x1, y1)
**    real deltax := x1 - x0
**    real deltay := y1 - y0
**    real deltaerr := abs(deltay / deltax)
**Assume deltax != 0 (line is not vertical),
**note that this division needs to be done
**in a way that preserves the fractional part
**    real error := 0.0 // No error at start
**    int y := y0
**    for x from x0 to x1
**        plot(x,y)
**        error := error + deltaerr
**        while error ≥ 0.5 then
**            y := y + sign(deltay) * 1
**            error := error - 1.0
*/

void		draw_line(t_point3d p1, t_point3d p2)
{
	int		dx;
	int		dy;
	int		derr;

	dx = (int)ABS(p1.x - p2.x);
	dy = (int)ABS(p1.y - p2.y);
	return ;
}

void		iterator(t_map *map, int x, int y)
{
	t_point3d	p;

	PROJP(GET_POINT(map, x, y), map);
	draw_line(GET_POINT(map, x, y), GET_POINT(map, x + 1, y));
}

void		render(t_mlx *mlx)
{
	iterate_points(mlx->map, iterator);
}
