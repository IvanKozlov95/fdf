/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:20:59 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/07 12:25:00 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "memory.h"
#include "ft_printf.h"

#include <mlx.h>

t_mlx	*init_mlx(char *title)
{
	t_mlx	*mlx;

	mlx = NULL;
	mlx = ft_memalloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, MIN_WIDTH, MIN_HEIGHT, title);
	mlx->image = image_init(mlx);
	if (mlx->mlx == NULL || mlx->window == NULL)
		del_mlx(&mlx);
	mlx->cam.offsetx = MIN_WIDTH / 2;
	mlx->cam.offsety = MIN_HEIGHT / 2;
	mlx->cam.x = 0.5;
	mlx->cam.y = 0.5;
	mlx->cam.scale = 32;
	mlx->style = 3;
	toggle_colors(mlx);
	return (mlx);
}

void	print_mlx(t_mlx *mlx)
{
	int			i;
	t_map		*map;
	t_point3d	p;

	i = -1;
	map = mlx->map;
	ft_printf("Points\n");
	while (++i < map->width * map->height)
	{
		p = GET_POINT(map, i % map->width, i / map->width);
		ft_printf("#%d (%d, %d, %d)\n", i, (int)p.x, (int)p.y, (int)p.z);
	}
}

void	del_mlx(t_mlx **mlx)
{
	if (*mlx)
		ft_free(3, (*mlx)->mlx, (*mlx)->window, *mlx);
	*mlx = NULL;
}
