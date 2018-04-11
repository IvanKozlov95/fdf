/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:27:07 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/10 16:53:41 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "fdf.h"
#include <mlx.h>

t_image		*image_init(t_mlx *mlx)
{
	t_image		*img;

	img = ft_memalloc(sizeof(t_image));
	img->image = mlx_new_image(mlx->mlx, MIN_WIDTH, MIN_HEIGHT);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp,
									&img->stride, &img->endian);
	img->bpp /= 8;
	return (img);
}
