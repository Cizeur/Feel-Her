/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_arrays.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:48:49 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/17 12:14:14 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft/get_next_line.h"
#include "libft/libft.h"
#include <stdlib.h>

static int	fill_board(t_filler *mst, const char *line, int *board, int len)
{
	int	j;

	j = 0;
	mst->alone = mst->alone || !mst->round ? mst->alone : 1;
	while (line[j] && j < len)
	{
		board[j] = P_OBS;
		if (line[j] == 'o' || line[j] == 'O')
			board[j] = P_O;
		else if (line[j] == 'x' || line[j] == 'X')
			board[j] = P_X;
		else if (line[j] == '.')
			board[j] = P_EMPTY;
		if (!mst->round && !mst->alone && (line[j] == 'o' || line[j] == 'x'))
			mst->alone = 0;
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

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (1);
	free(line);
	if (!(mst->board = (int **)ft_parser_alloc_double_array(mst->bszx,
			mst->bszy, sizeof(int))))
		return (1);
	i = 0;
	while (i < mst->bszy && get_next_line(0, &line) > -1)
	{
		if (ft_strlen(line) < 4
			|| fill_board(mst, line + 4, mst->board[i++], mst->bszx))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	return (i != mst->bszy);
}

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
	while (i < mst->pszy && get_next_line(0, &line) > -1)
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
