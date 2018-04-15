/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:38:22 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/15 16:57:59 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "matrix.h"
# include "structs.h"
# include "list.h"
# include <stdio.h>

/*
**	String constants
*/

# define USAGE "usage: ./fdf [filename]"
# define ERR_INVMAP "error: invalid map"
# define ERR_MLXINIT "error: mlx couldn't init"

enum		e_mouse
{
	none,
	left,
	right,
	mid,
	scr_up,
	scr_down
};

# define MIN_WIDTH 1000
# define MIN_HEIGHT 600

/*
**	MACROS
*/

# define PROJX(p, map) (p.x -= (double)(map->width - 1) / 2.0f)
# define PROJY(p, map) (p.y -= (double)(map->height - 1) / 2.0f)
# define PROJP(p, map) (PROJX(p, map) && PROJY(p, map))
# define GET_POINT(map, x, y) ((map->points[(y) * map->width + x]))
# define POINTDXINT(p1, p2) (((int)p1.x - (int)p2.x))
# define POINTDYINT(p1, p2) (((int)p1.y - (int)p2.y))
# define PERCENT(p, m) ((double)(p) / (double)(m) )
# define LERP(f, s, p) ((f) + ((s) - (f)) * p)
# define EXPR(c) ((c) || 1)
# define SWAP(a, b, t) (EXPR(t = a) && EXPR(a = b) && EXPR(b = t))
# define ASS(v, e) (v = e)

/*
**	Declarations
*/
t_map						*init_map(int width, int height);
int							populate_map(t_map **m, t_list *list);
int							read_map(int fd, t_map **m);
void						render(t_mlx *mlx);
void						iterate_points(t_mlx *mlx,
								void (*f)(t_mlx *, int, int));

t_image						*image_init(t_mlx *mlx);

t_point3d					point_project(t_point3d	p, t_mlx *mlx);

t_bshm_line					line_init(t_point3d p1, t_point3d p2);

void						log_point(t_point3d p);
void						print_ponts(t_mlx *mlx);

void						ft_free_split(char **sp);
int							get_color(int c1, int c2, double p);

int							hook_mouse_move(int x, int y, t_mlx *mlx);
int							hook_mouse_down(int button,
								int x, int y, t_mlx *mlx);
int							hook_mouse_up(int button, int x, int y, t_mlx *mlx);
int							hook_keys(int key, t_mlx *mlx);


#endif
