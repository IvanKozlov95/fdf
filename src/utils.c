/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:43:15 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/15 21:22:19 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "fdf.h"

void	ft_free_split(char **sp)
{
	char	**head;

	head = sp;
	while (sp && *sp)
	{
		ft_memdel((void **)sp);
		sp++;
	}
	ft_memdel((void **)&head);
}

int		get_color(int c1, int c2, double p)
{
	int		r;
	int		b;
	int		g;

	if (c1 == c2)
		return (c1);
	if (p == 0.0)
		return (c1);
	if (p == 1.0)
		return (c2);
	r = LERP((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = LERP((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = LERP(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}

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

void		toggle_colors(t_mlx *mlx)
{
	mlx->style = mlx->style == 3
		? 0 : mlx->style + 1;
	if (mlx->style == 0)
	{
		mlx->c_max = 0xFFFFFF;
		mlx->c_min = 0xFFFFFF;
	}
	if (mlx->style == 1)
	{
		mlx->c_max = 0xFFFFFF;
		mlx->c_min = 0xFF0000;
	}
	if (mlx->style == 2)
	{
		mlx->c_max = 0xFFFFFF;
		mlx->c_min = 0x00FF00;
	}
	if (mlx->style == 3)
	{
		mlx->c_max = 0xFFFFFF;
		mlx->c_min = 0x0000FF;
	}
	if (mlx->style == 4)
	{
		mlx->c_max = 0xFF00FF;
		mlx->c_min = 0x00FF00;
	}
}
