/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 21:02:12 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/07 12:31:56 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

#include <mlx.h>

void	bind_hooks(t_mlx *mlx)
{
	mlx_key_hook(mlx->window, hook_keys, mlx);
	mlx_hook(mlx->window, 4, 0, hook_mouse_down, mlx);
	mlx_hook(mlx->window, 5, 0, hook_mouse_up, mlx);
	mlx_hook(mlx->window, 6, 0, hook_mouse_move, mlx);
}

int		hook_keys(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		del_mlx(&mlx);
		exit(0);
	}
	else if (key == 32)
		mlx->map->d_max++;
	else if (key == 2)
		mlx->map->d_max--;
	else if (key == 8)
	{
		toggle_colors(mlx);
		fill_colors(mlx->map, mlx->c_min, mlx->c_max);
	}
	render(mlx);
	return (0);
}

int		hook_mouse_down(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse.button = button;
	if (button == scr_up)
	{
		x = mlx->cam.scale * 10 / 100;
		if (!x)
			mlx->cam.scale++;
		mlx->cam.scale += x;
	}
	else if (button == scr_down)
		mlx->cam.scale -= mlx->cam.scale * 0.1;
	if (button == scr_up || button == scr_down)
		render(mlx);
	return (1);
}

int		hook_mouse_up(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	(void)button;
	mlx->mouse.button = none;
	return (1);
}

int		hook_mouse_move(int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	mlx->mouse.lastx = mlx->mouse.x;
	mlx->mouse.lasty = mlx->mouse.y;
	mlx->mouse.x = x;
	mlx->mouse.y = y;
	if (mlx->mouse.button == right)
	{
		mlx->cam.offsetx += (x - mlx->mouse.lastx);
		mlx->cam.offsety += (y - mlx->mouse.lasty);
	}
	else if (mlx->mouse.button == left)
	{
		mlx->cam.x += (mlx->mouse.lasty - y) / 200.0f;
		mlx->cam.y -= (mlx->mouse.lastx - x) / 200.0f;
	}
	if (mlx->mouse.button != none)
		render(mlx);
	return (1);
}
