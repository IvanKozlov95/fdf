/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:38:22 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/09 21:23:26 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "matrix.h"
# include "list.h"
# include "math.h"

/*
**	String constants
*/

# define USAGE "usage: ./fdf [filename]"
# define ERR_INVMAP "error: invalid map"
# define ERR_MLXINIT "error: mlx couldn't init"


struct						s_image
{
	void					*image;
	void					*ptr;
	int						bpp;
	int						stride;
	int						endian;
};
typedef struct s_image		t_image;

struct						s_point3d
{
	double					x;
	double					y;
	double					z;
	void					*info;
};
typedef struct s_point3d	t_point3d;

struct						s_map
{
	int						width;
	int						height;
	t_point3d				*points;
};
typedef struct s_map		t_map;

struct						s_mlx
{
	void					*mlx;
	t_image					*image;
	void					*window;
	t_map					*map;
};
typedef struct s_mlx		t_mlx;

/*
**	MACROS
*/
# define SETZ(p, _z) (p.z = _z)
# define SETXYZ(p, _x, _y, _z) (SETXY(p, _x, _y) && SETZ(p, _z))

# define PROJX(p, map) (p.x -= (double)(map->width - 1) / 2.0f)
# define PROJY(p, map) (p.y -= (double)(map->height - 1) / 2.0f)
# define PROJP(p, map) (PROJX(p, map) && PROJY(p, map))
# define GET_POINT(map, x, y) (map->points[y * map->width + x])

/*
**	Declarations
*/
t_map						*init_map(int width, int height);
int							populate_map(t_map **m, t_list *list);
int							read_map(int fd, t_map **m);
void						render(t_mlx *mlx);

t_image						*image_init(t_mlx *mlx);

void						ft_free_split(char **sp);

#endif
