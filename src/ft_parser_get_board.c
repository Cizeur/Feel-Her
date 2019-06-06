/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_board.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:57:36 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 10:28:51 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

static int	fill_board(const char *line, int *board, int len, int *player)
{
	int	j;

	j = 0;
	while (line[j] && j < len)
	{
		if (line[j] == '.')
			board[j] = P_EMPTY;
		else if (!*player && line[j] == 'o')
		{
			*player = P_X;
			board[j] = P_O;
		}
		else if (line[j] == 'o' || line[j] == 'O')
			board[j] = P_O;
		else if (line[j] == 'x' || line[j] == 'X')
			board[j] = P_X;
		else
			return (1);
		++j;
	}
	if (line[j] || j < len)
		return (1);
	return (0);
}

int			ft_parser_get_board(t_filler *mst)
{
	int		i;
	char	*line;
	int		margin;

	line = NULL;
	if (get_next_line_single_fd(0, &line) < 0)
		return (1);
	free(line);
	if (!(mst->board = (int **)ft_parser_alloc_double_array(mst->bszx,
			mst->bszy, sizeof(int))))
		return (1);
	margin = ft_intlen(mst->bszy - 1) + 2;
	i = 0;
	while (i < mst->bszy && get_next_line_single_fd(0, &line) > -1)
	{
		if (fill_board(line + margin, mst->board[i++], mst->bszx, &mst->player))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	mst->player = !mst->player ? P_O : mst->player;
	return (i != mst->bszy);
}
