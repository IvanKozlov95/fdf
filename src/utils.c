/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivankozlov <ivankozlov@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:43:15 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/15 13:47:25 by ivankozlov       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"
#include "fdf.h"

void	ft_free_split(char **sp)
{
	char	**head;

	head = sp;
	while (sp && *sp)
	{
		ft_memdel((void **)sp);
		sp++;
	}
	ft_memdel((void **)&head);
}

int		get_color(int c1, int c2, double p)
{
	int		r;
	int		b;
	int		g;

	if (c1 == c2)
		return (c1);
	r = LERP((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = LERP((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = LERP(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}
