/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_piece_dims.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:20:48 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 09:37:05 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

int			ft_parser_get_piece_dims(t_filler *mst)
{
	char	*line;
	int		c;

	c = 0;
	line = NULL;
	if (get_next_line_single_fd(0, &line) < 0)
		return (1);
	if (ft_strncmp(line, "Piece ", 6))
	{
		free(line);
		return (1);
	}
	ft_parser_get_dims(line + 6, &mst->pszx, &mst->pszy);
	free(line);
	return (0);
}
