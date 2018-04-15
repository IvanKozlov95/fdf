/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:10:48 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/15 16:58:43 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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
