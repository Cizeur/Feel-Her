/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:26:19 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 16:26:32 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void			ft_amp_extract(t_master *mstr, int val)
{
	if (!val)
		return;
	if (val > 0 && !mstr->amp_o[0])
		{
			mstr->amp_o[0] = val;
			mstr->amp_o[1] = val;
		}
	else if (val < 0 && !mstr->amp_x[0])
		{
			mstr->amp_x[0] = val;
			mstr->amp_x[1] = val;
		}
	else if (val > 0)
	{
		mstr->amp_o[0] = ft_max(mstr->amp_o[0], val);
		mstr->amp_o[1] = ft_min(mstr->amp_o[1], val);
		mstr->amp_o[2] = ft_abs(mstr->amp_o[0] - mstr->amp_o[1]);
	}
	else if (val < 0)
	{
		mstr->amp_x[0] = ft_min(mstr->amp_x[0], val);
		mstr->amp_x[1] = ft_max(mstr->amp_x[1], val);
		mstr->amp_x[2] = ft_abs(mstr->amp_x[0] - mstr->amp_x[1]);
	}

}

static int		ft_line_extract(t_master *mstr, char *line, int j)
{
	char *start;
	int *pos;
	int i;

	start = line + 4;
	i = -1;
	while(++i < mstr->size[1] && start[i])
	{
		pos = &mstr->map[j][i][0];
		*pos += start[i] == 'O' ? 1 : 0;
		*pos -= start[i] == 'X' ? 1 : 0;
		*pos = start[i] == 'o' ? 1 : *pos;
		*pos = start[i] == 'x' ? -1 : *pos;
		ft_amp_extract(mstr, *pos);
	}
	return (i == mstr->size[1] ? 1 : 0);
}

int		ft_parser_map_update(t_master *mstr, int *size)
{
	int j;
	int check_line;
	char	line[BUFFER_LINE];

	ft_bzero(mstr->amp_o, sizeof(int) * 3);
	ft_bzero(mstr->amp_x, sizeof(int) * 3);
	ft_parser_gnl(mstr, line);
	if (!mstr->current)
		return(-1);
	j = -1;
	check_line = 1;
	while (check_line && ++j < size[0] && ft_parser_gnl(mstr, line))
		check_line = ft_line_extract(mstr, line, j);
	return (check_line && mstr->current ? 1 : 0);
}
