/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:40:50 by ikozlov           #+#    #+#             */
/*   Updated: 2018/04/09 15:46:38 by ikozlov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "list.h"
#include "strings.h"
#include "get_next_line.h"

static int	cleanup(t_list **list)
{
	ft_lstdel(list, ft_free_content);
	return (0);
}

static int	read_lines(int fd, t_list **list)
{
	int		ret;
	int		expected;
	char	*line;
	t_list	*tmp;

	expected = -1;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (expected == -1)
			expected = (int)ft_count_words(line, ' ');
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		LST_ADDCREATE(list, tmp);
		if (expected != (int)ft_count_words(line, ' '))
			return (cleanup(list));
		ft_strdel(&line);
	}
	if (ret == -1 || expected == -1)
		return (cleanup(list));
	return (expected);
}

int		read_map(int fd, t_map **m)
{
	int		wc;
	t_list	*list;

	list = NULL;
	if (!(wc = read_lines(fd, &list)))
		return (0);
	*m = init_map(ft_lstcount(list), wc);
	populate_map(m, list);
	cleanup(&list);
	return (1);
}
