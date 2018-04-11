/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:04:31 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/10 22:07:20 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdio.h>

void		iterate_points(t_mlx *mlx, void (*f)(t_mlx *, int, int))
{
	int		i;
	int		size;
	t_map	*map;

	i = -1;
	map = mlx->map;
	size = map->height * map->width;
	while (++i < size)
		f(mlx, i % map->width, i / map->width);
}

/*
**	function line(x0, y0, x1, y1)
**	real deltax := x1 - x0
**	real deltay := y1 - y0
**	real deltaerr := abs(deltay / deltax)
**	Assume deltax != 0 (line is not vertical),
**	note that this division needs to be done
**	in a way that preserves the fractional part
**	real error := 0.0 // No error at start
**	int y := y0
**	for x from x0 to x1
**		plot(x,y)
**		error := error + deltaerr
**		while error ≥ 0.5 then
**			y := y + sign(deltay) * 1
**			error := error - 1.0
*/

void		draw_line(t_mlx *mlx, t_bshm_line line)
{
	int		x;
	int		y;

	x = (int)line.s.x;
	y = (int)line.s.y;
	while (x <= line.e.x)
	{
		if (x > 0 && x <= MIN_WIDTH && y > 0 && y <= MIN_HEIGHT)
		{
			*(int *)(mlx->image->ptr +
				((x + y * MIN_WIDTH) * mlx->image->bpp)) = 0xff0000;
		}
		line.err += line.derr;
		while (line.err > 0.5)
			(y += line.sy) && (line.err -= 1);
		x += line.sx;
	}
}

void		draw_lines(t_mlx *mlx, int x, int y)
{
	t_point3d	p;
	t_point3d	p2;

	p = point_project(GET_POINT(mlx->map, x, y), mlx);
	if (x + 1 < mlx->map->width)
	{
		p2 = point_project(GET_POINT(mlx->map, x + 1, y), mlx);
		draw_line(mlx, line_init(p, p2));
	}
	if (y + 1 < mlx->map->height)
	{
		p2 = point_project(GET_POINT(mlx->map, x, y + 1), mlx);
		draw_line(mlx, line_init(p, p2));
	}
}

void		light_points(t_mlx *mlx, int x, int y)
{
	t_point3d	p;

	p = GET_POINT(mlx->map, x, y);
	p = point_project(p, mlx);
	if (p.x > 0 && p.x <= MIN_WIDTH && p.y >= 0 && p.y <= MIN_HEIGHT)
		*(int *)(mlx->image->ptr +
				((int)p.x + (int)p.y * MIN_WIDTH) * mlx->image->bpp) = 0x00ff00;
}

void		asd(t_mlx *mlx, int x, int y)
{
	t_point3d	p;
	t_point3d	p2;

	p = point_project(GET_POINT(mlx->map, x, y), mlx);
	p2 = point_project(GET_POINT(mlx->map, x, y + 1), mlx);
	draw_line(mlx, line_init(p, p2));
}

void		render(t_mlx *mlx)
{
	iterate_points(mlx, draw_lines);
	iterate_points(mlx, light_points);
	// asd(mlx, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
