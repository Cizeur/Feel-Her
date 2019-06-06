/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_board_dims.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 08:53:06 by yforeau           #+#    #+#             */
/*   Updated: 2019/06/06 09:06:40 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "get_next_line.h"

static int	get_players(t_filler *mst, char *line)
{
	int	c;
	int	r;

	c = -1;
	while (++c < 3 && (r = get_next_line_single_fd(0, &line)) > 0)
	{
		if (!(c % 2))
		{
			if (ft_strncmp(line, "$$$ exec p", 10)
				|| !(line[10] == '1' || line[10] == '2')
				|| ft_strncmp(line + 11, " : [", 3)
				|| ft_strlen(line + 15) < 2)
				break ;
			if (line[10] == '1')
				mst->player_1 = ft_strndup(line + 15, ft_strlen(line + 15) - 1);
			else
				mst->player_2 = ft_strndup(line + 15, ft_strlen(line + 15) - 1);
		}
		else if (ft_strncmp(line, "launched ", 9))
			break ;
		free(line);
	}
	if (c != 3 && r >= 0)
			free(line);
	return (c == 3 ? 0 : -1);
}

static int	check_line(t_filler *mst, char *line, int c)
{
	if ((line[0] == '<' && !c) || line[0] == '#')
		free(line);
	else if (!ft_strncmp(line, "launched ", 9) && c)
	{
		free(line);
		return (get_players(mst, line));
	}
	else if (!ft_strncmp(line, "Plateau ", 8) && c)
		return (1);
	else
	{
		free(line);
		return (-1);
	}
	return (0);
}

int			ft_parser_get_board_dims(t_filler *mst)
{
	char	*line;
	int		c;
	int		r;

	c = 0;
	line = NULL;
	while ((r = get_next_line_single_fd(0, &line)) > 0)
	{
		if ((r = check_line(mst, line, c)) == -1)
			return (1);
		else if (r)
			break ;
		++c;
	}
	if (r < 0 || !line)
		return (1);
	ft_parser_get_dims(line + 8, &mst->bszx, &mst->bszy);
	free(line);
	return (0);
}
