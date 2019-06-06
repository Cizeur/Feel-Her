/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_piece.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:22:46 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 09:36:41 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

static int	fill_piece(const char *line, char *piece, int len)
{
	int	j;

	j = 0;
	while (line[j] && j < len)
	{
		if (line[j] == '.' || line[j] == '*')
			piece[j] = line[j];
		else
			return (1);
		++j;
	}
	return (line[j] || j < len);
}

int			ft_parser_get_piece(t_filler *mst)
{
	int		i;
	char	*line;

	line = NULL;
	if (!(mst->piece = (char **)ft_parser_alloc_double_array(mst->pszx,
			mst->pszy, sizeof(char))))
		return (1);
	i = 0;
	while (i < mst->pszy && get_next_line_single_fd(0, &line) > -1)
	{
		if (fill_piece(line, mst->piece[i++], mst->pszx))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	return (i != mst->pszy);
}
