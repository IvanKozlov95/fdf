/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:21:27 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/13 23:31:10 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point3d	rotate(t_point3d p)
{
	t_point3d	v;
	double		x;
	double		y;
	double		z;

	x = p.x;
	z = p.z;
	v.x = cos(0.5) * x + sin(0.5) * z;
	v.z = -sin(0.5) * x + cos(0.5) * z;
	y = p.y;
	z = v.z;
	v.y = cos(0.5) * y - sin(0.5) * z;
	v.z = sin(0.5) * y + cos(0.5) * z;
	return (v);
}

t_point3d	point_project(t_point3d p, t_mlx *mlx)
{
	int		scale;
	int		offsetx;
	int		offsety;

	scale = 32;
	offsetx = MIN_WIDTH / 2;
	offsety = MIN_HEIGHT / 2;
	p.x -= (double)(mlx->map->width - 1) / 2.0f;
	p.y -= (double)(mlx->map->height - 1) / 2.0f;
	p.z -= (double)(1 + 1) / 2.0f;
	p = rotate(p);
	p.x *= scale;
	p.y *= scale;
	p.x += offsetx;
	p.y += offsety;
	return (p);
}
