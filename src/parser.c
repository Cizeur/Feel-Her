/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 12:12:35 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/05 15:22:26 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_dims.h"

static int	exit_parser(void)
{
	write(1, "map error\n", 10);
	return (1);
}

static int	get_board(t_filler *mst)
{
	char	*line;

	line = NULL;
	if (get_next_list_single_fd(0, &line) <= 0)
		return (1);
	free(line);
	mst->board = (int **)ft_alloc_double_array(mst->bszx,
			mst->bszy, sizeof(int));
}

int			parser(t_filler *mst)
{
	if (get_board_dims(mst) || !mst->bszx || !mst->bszy)
		return (exit_parser());
	if (get_board(mst))
		return (exit_parser());
}
