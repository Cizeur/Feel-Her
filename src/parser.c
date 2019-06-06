/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:12:35 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 13:57:37 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

static int	exit_parser(t_filler *mst)
{
	if (mst->board)
		ft_parser_free_double_array((void **)mst->board);
	if (mst->piece)
		ft_parser_free_double_array((void **)mst->piece);
	write(2, "map error\n", 10);
	return (1);
}

int			parser(t_filler *mst)
{
	int		r;
	char	*line;

	if (ft_parser_get_player(mst))
		return (exit_parser(mst));
	if (ft_parser_get_board_dims(mst))
		return (exit_parser(mst));
	if (ft_parser_get_board(mst))
		return (exit_parser(mst));
	if (ft_parser_get_piece_dims(mst))
		return (exit_parser(mst));
	if (ft_parser_get_piece(mst))
		return (exit_parser(mst));
	line = NULL;
	r = get_next_line_single_fd(0, &line);
	if (r > -1)
		free(line);
	return (r > 0);
}
