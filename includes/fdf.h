/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:38:22 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/09 15:43:30 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "matrix.h"
# include "list.h"
# include "math.h"

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


/*
**	MACROS
*/
# define SETZ(p, _z) (p.z = _z)
# define SETXYZ(p, _x, _y, _z) (SETXY(p, _x, _y) && SETZ(p, _z))

/*
**	Declarations
*/
t_map						*init_map(int width, int height);
int							populate_map(t_map **m, t_list *list);

#endif