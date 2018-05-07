/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:27:59 by ikozlov           #+#    #+#             */
/*   Updated: 2018/05/07 12:43:24 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "ft_printf.h"

#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>

void	die(int code, char *msg)
{
	ft_printf("%s\n", msg);
	exit(code);
}

void	display_help(void)
{
	ft_printf("---------------------------------------------------------\n");
	ft_printf("|\t\t\tFDF @ 42\t\t\t|\n");
	ft_printf("|\t\tmouse left - rotate\t\t\t|\n");
	ft_printf("|\t\tmouse right - move\t\t\t|\n");
	ft_printf("|\t\twheel - zoom in/out\t\t\t|\n");
	ft_printf("|\t\tc - change color\t\t\t|\n");
	ft_printf("|\t\tu - increase z axis\t\t\t|\n");
	ft_printf("|\t\td - decrease z axis\t\t\t|\n");
	ft_printf("---------------------------------------------------------\n");
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
	display_help();
	fill_colors(mlx->map, mlx->c_min, mlx->c_max);
	render(mlx);
	bind_hooks(mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
