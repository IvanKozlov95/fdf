/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:21:27 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/07 12:10:33 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point3d	rotate(t_point3d p, t_cam cam)
{
	t_point3d	v;
	double		x;
	double		y;
	double		z;

	x = p.x;
	z = p.z;
	v.x = cos(cam.y) * x + sin(cam.y) * z;
	v.z = -sin(cam.y) * x + cos(cam.y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(cam.x) * y - sin(cam.x) * z;
	v.z = sin(cam.x) * y + cos(cam.x) * z;
	v.color = p.color;
	return (v);
}

t_point3d	point_project(t_point3d p, t_mlx *mlx)
{
	p.x -= (double)(mlx->map->width - 1) / 2.0f;
	p.y -= (double)(mlx->map->height - 1) / 2.0f;
	p.z = p.z == mlx->map->d_min ?
		p.z : p.z + (mlx->map->d_max + mlx->map->d_min) / 2.0f;
	p = rotate(p, mlx->cam);
	p.x *= mlx->cam.scale;
	p.y *= mlx->cam.scale;
	p.x += mlx->cam.offsetx;
	p.y += mlx->cam.offsety;
	return (p);
}
