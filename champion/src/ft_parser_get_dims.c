/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_dims.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:50:25 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/19 13:36:19 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "libft/libft.h"
#include "libft/get_next_line.h"

static void	ft_parser_get_dims(char *dims, int *x, int *y)
{
	*y = ft_atoi(dims);
	while (*dims && *dims > 47 && *dims < 58)
		++dims;
	*x = ft_atoi(dims);
}

int			ft_parser_get_board_dims(t_filler *mst)
{
	char	*line;
	int		r;

	line = NULL;
	if ((r = get_next_line(0, &line)) > 0
		&& !ft_strncmp(line, "Plateau ", 8))
		ft_parser_get_dims(line + 8, &mst->bszx, &mst->bszy);
	if (r > -1)
		free(line);
	return (r < 1 || !mst->bszx || !mst->bszy);
}

int			ft_parser_get_piece_dims(t_filler *mst)
{
	char	*line;
	int		c;

	c = 0;
	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (1);
	if (ft_strncmp(line, "Piece ", 6))
	{
		free(line);
		return (1);
	}
	ft_parser_get_dims(line + 6, &mst->pszx, &mst->pszy);
	free(line);
	return (!mst->pszx || !mst->pszy);
}
