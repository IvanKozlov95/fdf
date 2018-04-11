/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:04:31 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/10 15:49:00 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <math.h>

void		iterate_points(t_mlx *mlx, void (*f)(t_mlx *, int, int))
{
	int		i;
	int		size;
	t_map	*map;

	i = -1;
	map = mlx->map;
	size = map->height * map->width;
	while (++i < size)
		f(mlx, i % map->width, i / map->height);
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

void		draw_line(t_mlx *mlx, t_point3d p1, t_point3d p2)
{
	int		dx;
	int		dy;
	int		derr;
	int		x;
	int		y;
	double	err;

	dx = (int)ABS(p1.x - p2.x);
	dy = (int)ABS(p1.y - p2.y);
	derr = ABS(dy - dx);
	x = (int)p1.x - 1;
	y = (int)p1.y;
	err = 0.5;
	while (++x < (int)p2.x)
	{
		if (x > 0 && x <= MIN_WIDTH && y > 0 && y <= MIN_HEIGHT)
			*(int *)(mlx->image->ptr + (x + y * MIN_WIDTH) * mlx->image->bpp) = 0xff0000;
		err += derr;
		if (err > 0.5)
		{
			y += dy;
			err--;
		}
	}
	return ;
}

void		iterator(t_mlx *mlx, int x, int y)
{

void		light_points(t_mlx *mlx, int x, int y)
{
	t_point3d	p;

	p = GET_POINT(mlx->map, x, y);
	p = point_project(p, mlx);
	if (x == 0)
		log_point(p);
	if (p.x > 0 && p.x <= MIN_WIDTH && p.y >= 0 && p.y <= MIN_HEIGHT)
		*(int *)(mlx->image->ptr +
				((int)p.x + (int)p.y * MIN_WIDTH) * mlx->image->bpp) = 0x00ff00;
}

void		render(t_mlx *mlx)
{
	iterate_points(mlx, iterator);
	iterate_points(mlx, light_points);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
}
