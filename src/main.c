/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:35:24 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/10 15:40:44 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "memory.h"
#include "fdf.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>

void	die(int code, char *msg)
{
	ft_printf("%s\n", msg);
	exit(code);
}

void	del_mlx(t_mlx **mlx)
{
	if (*mlx)
		ft_free(3, (*mlx)->mlx, (*mlx)->window, *mlx);
	*mlx = NULL;
}

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
	return (mlx);
}

int		main(int ac, char *av[])
{
	int		fd;
	t_map	*map;
	t_mlx	*mlx;

	map = NULL;
	if (ac != 2)
		die(0, USAGE);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !read_map(fd, &map))
		die(1, ERR_INVMAP);
	mlx = init_mlx(av[1]);
	if (mlx == NULL)
		die(1, ERR_MLXINIT);
	mlx->map = map;
	render(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
