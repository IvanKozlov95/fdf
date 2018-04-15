/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 21:02:12 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/14 21:25:07 by ikozlov          ###   ########.fr       */
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
