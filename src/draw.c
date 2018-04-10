/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:04:31 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/09 21:36:39 by ikozlov          ###   ########.fr       */
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

void		draw_line(t_point3d p1, t_point3d p2)
{
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
