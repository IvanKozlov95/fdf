/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 16:46:37 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/20 22:43:29 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

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
	int						color;
	void					*info;
};
typedef struct s_point3d	t_point3d;

struct						s_map
{
	int						width;
	int						height;
	int						d_max;
	int						d_min;
	t_point3d				*points;
};
typedef struct s_map		t_map;

struct						s_mouse
{
	int		button;
	int		x;
	int		y;
	int		lastx;
	int		lasty;
};
typedef struct s_mouse		t_mouse;

struct						s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			scale;
};
typedef struct s_cam		t_cam;

struct						s_mlx
{
	void					*mlx;
	t_image					*image;
	void					*window;
	t_map					*map;
	t_mouse					mouse;
	t_cam					cam;
	int						style;
	int						c_min;
	int						c_max;
};
typedef struct s_mlx		t_mlx;

struct						s_bshm_line
{
	int						dx;
	int						dy;
	int						sx;
	int						sy;
	int						er;
	int						change;
	t_point3d				p1;
	t_point3d				p2;
};
typedef struct s_bshm_line	t_bshm_line;

#endif
