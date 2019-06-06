/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:12:35 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 08:42:46 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_dims.h"

static int	exit_parser(t_filler *mst)
{
	if (mst->board)
		ft_parser_free_double_array((void **)mst->board);
	if (mst->player_1)
		free(mst->player_1);
	if (mst->player_2)
		free(mst->player_2);
	write(2, "map error\n", 10);
	return (1);
}

static int	fill_board(const char *line, int *board, int len)
{
	int	j;

	j = 0;
	while (line[j] && j < len)
	{
		if (line[j] == '.')
			board[j] = P_EMPTY;
		else if (!mst->player && line[j] == 'o')
		{
			mst->player = P_X;
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
	mst->player = !mst->player ? P_O : mst->player;
	return (0);
}

static int	get_board(t_filler *mst)
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
	while (i < mst->bszx && get_next_line_single_fd(0, &line) > -1)
	{
		if (fill_board(line + margin, mst->board[i++], mst->bszx))
		{
			free(line);
			return (1);
		}
		free(line);
	}
	return (i != mst->bszx);
}

int			parser(t_filler *mst)
{
	if (get_board_dims(mst) || !mst->bszx || !mst->bszy)
		return (exit_parser(mst));
	if (get_board(mst))
		return (exit_parser(mst));
	return (0);
}
