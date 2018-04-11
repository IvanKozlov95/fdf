/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:52:37 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/10 20:44:46 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

t_matrix	init_matrix(int rows, int cols)
{
	t_matrix	mtx;

	mtx.m = ft_memalloc(sizeof(t_point3d *) * rows);
	mtx.rows = rows;
	mtx.cols = cols;
	return (mtx);
}

int		populate_map(t_map **m, t_list *list)
{
	int			i;
	int			j;
	t_point3d	*p;
	t_list		*head;
	char		**split;

	head = list;
	i = -1;
	while (++i < (*m)->height)
	{
		j = -1;
		split = ft_strsplit(list->content, ' ');
		while (++j < (*m)->width)
			SETXYZ((p = &GET_POINT((*m), j, i)), j, i, ft_atoi(split[j]));
		ft_free_split(split);
		list = list->next;
	}
	return (1);
}

t_map	*init_map(int width, int height)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	map->width = width;
	map->height = height;
	map->points = ft_memalloc(sizeof(t_point3d) * width * height);
	return (map);
}
