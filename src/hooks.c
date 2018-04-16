/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 21:02:12 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/15 17:01:05 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <stdlib.h>

int		hook_keys(int key, t_mlx *mlx)
{
	printf("Key pressed. Code #%d\n", key);
	if (key == 53)
		exit(0);
	else if (key == 32)
		mlx->depth++;
	else if (key == 2)
		mlx->depth--;
	render(mlx);
	return (0);
}

int		hook_mouse_down(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse.button = button;
	printf("Button %d\n", button);
	return (1);
}

int		hook_mouse_up(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	(void)button;
	printf("Here\n");
	mlx->mouse.button = none;
	return (1);
}

int		hook_mouse_move(int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	(void)mlx;
	return (1);
}
