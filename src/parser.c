/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:12:35 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 16:16:00 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

static int	exit_parser(t_filler *mst, char *err)
{
	if (mst->board)
		ft_parser_free_double_array((void **)mst->board);
	if (mst->piece)
		ft_parser_free_double_array((void **)mst->piece);
	dprintf(2, "map error: %s\n", err);
	return (1);
}

int			parser(t_filler *mst)
{
	if (!mst->player && ft_parser_get_player(mst))
		return (exit_parser(mst, "get_player"));
	if (ft_parser_get_board_dims(mst))
		return (exit_parser(mst, "get_board_dims"));
	if (ft_parser_get_board(mst))
		return (exit_parser(mst, "get_board"));
	if (ft_parser_get_piece_dims(mst))
		return (exit_parser(mst, "get_piece_dims"));
	if (ft_parser_get_piece(mst))
		return (exit_parser(mst, "get_piece"));
	return (0);
}
