/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 21:35:24 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/09 16:50:59 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>

void	die(int code, char *msg)
{
	ft_printf("%s\n", msg);
	exit(code);
}

int		main(int ac, char *av[])
{
	int		fd;
	t_map	*map;

	map = NULL;
	if (ac != 2)
		die(0, "usage: ./fdf [filename]");
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || !read_map(fd, &map))
		die(1, "error: invalid map");
	return (0);
}
