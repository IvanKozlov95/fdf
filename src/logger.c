/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:48:59 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/13 22:49:56 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void		log_point(t_point3d p)
{
	printf("Point: %f, %f, %f\n", p.x, p.y, p.z);
}

void		print_point(t_mlx *mlx, int x, int y)
{
	log_point(point_project(GET_POINT(mlx->map, x, y), mlx));
}

void		print_ponts(t_mlx *mlx)
{
	int		i;
	int		size;
	t_map	*map;

	i = -1;
	map = mlx->map;
	size = map->height * map->width;
	while (++i < size)
		print_point(mlx, i % map->width, i / map->width);
}
