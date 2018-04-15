/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 14:52:37 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/14 22:55:26 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <limits.h>

static void	set_depths_map(t_map *map, t_point3d *p)
{
	if (map->d_max < p->z)
		map->d_max = p->z;
	if (map->d_min > p->z)
		map->d_min = p->z;
}

void		fill_colors(t_map *m)
{
	int			i;
	int			j;
	int			c;
	t_point3d	*p;

	i = -1;
	while (++i < m->height)
	{
		j = -1;
		while (++j < m->width)
		{
			p = &GET_POINT(m, j, i);
			c = get_color(0xff0000, 0xffffff,
				LERP(m->d_min, m->d_max, PERCENT(p->z, m->d_max - m->d_min)));
			p->color = c;
		}
	}
}

int			populate_map(t_map **m, t_list *list)
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
		{
			SETXYZ((p = &GET_POINT((*m), j, i)), j, i, ft_atoi(split[j]));
			set_depths_map(*m, p);
		}
		ft_free_split(split);
		list = list->next;
	}
	fill_colors(*m);
	return (1);
}

t_map		*init_map(int width, int height)
{
	t_map	*map;

	map = ft_memalloc(sizeof(t_map));
	map->width = width;
	map->height = height;
	map->d_max = INT_MIN;
	map->d_min = INT_MAX;
	map->points = ft_memalloc(sizeof(t_point3d) * width * height);
	return (map);
}
