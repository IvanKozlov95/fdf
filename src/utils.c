/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:43:15 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/09 16:47:37 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

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
