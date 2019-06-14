/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_parser_stockage.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:49:23 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/20 17:36:17 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

static void		ft_player_extract(t_master *mstr,char *line)
{
	char *shorter;
	char **player;

	if (ft_strstr(line, EXEC_1_S))
		player = &mstr->player_1;
	else
		player = &mstr->player_2;
	if ((shorter = ft_strrchr(line, '[')))
		line = shorter + 1;
	if ((shorter = ft_strrchr(line, '/')))
		line = shorter + 1;
	if ((shorter = ft_strrchr(line, ']')))
		*shorter = 0;
	if ((shorter = ft_strrchr(line, '.')))
		*shorter = 0;
	*player = ft_strdup(line);
}

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

int 					ft_line_find(t_master *mstr, char  *line)
{
	char *pos;
	char *bufferpos;

	ft_bzero(line, BUFFER_LINE);
	bufferpos = mstr->buffer_pos;
	if (!bufferpos)
		return (0);
	while(bufferpos && !(pos = ft_strchr(bufferpos, '\n')))
	{
		ft_strcpy(line + ft_strlen(line), bufferpos);
		mstr->current = mstr->current->next;
		bufferpos = mstr->current ? mstr->current->content : NULL;
	}
	if ((mstr->buffer_pos = bufferpos))
	{
		mstr->buffer_pos = pos + 1;
		ft_strcpy(line + ft_strlen(line), bufferpos);
		pos = ft_strchr(line, '\n');
		*pos = 0;
	} 
	return (1);
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
		mstr->map[j][i][1] = 0;
		ft_amp_extract(mstr, *pos);
	}
	return (i == mstr->size[1] ? 1 : 0);
}

static int		ft_parser_map_extract(t_master *mstr, int *size)
{
	int j;
	int check_line;
	char	line[BUFFER_LINE];

	ft_bzero(mstr->amp_o, sizeof(int) * 3);
	ft_bzero(mstr->amp_x, sizeof(int) * 3);
	ft_line_find(mstr, line);
	if (!mstr->current)
		return(-1);
	j = -1;
	check_line = 1;
	while (check_line && ++j < size[0] && ft_line_find(mstr, line))
		check_line = ft_line_extract(mstr, line, j);
	return (check_line && mstr->current ? 1 : 0);
}


static void		ft_parser_output_skimmer(t_master *mstr, int *size)
{
	char	line[2 * MAX_XRES + 1];
	int		size_check;

	size_check = 1;
	while (size_check && ft_line_find(mstr, line))
	{
		if (line == ft_strstr(line, INVERT))
			ft_swap(&(mstr->color_1_tg), &(mstr->color_2_tg));
		if (ft_strstr(line, END_S))
			mstr->still_reading = 0;
		if (ft_strstr(line, LAUNCH_S))
			size_check = 1;
		else if (ft_strstr(line, EXEC_1_S) || ft_strstr(line, EXEC_2_S))
			ft_player_extract(mstr, line);
		else if (ft_strstr(line, PLATEAU_S))
		{
			if ((size_check = ft_parser_check_size(line, size)))
				size_check = ft_parser_map_extract(mstr,size);
			break;
		}
	}
	if (!size_check || size[0] <= 0)
		ft_exit(FAIL_LINE_LEN, mstr);
}

void			ft_check_score(t_master *mstr, int *size)
{
	int i;
	int j;
	int check[2];

	j = -1;
	ft_bzero(check, sizeof(check));
	while ((i = -1) && ++j < size[0])
	{
		while (++i < size[1])
		{
			check[0] = mstr->map[j][i][0] == 1 ? 1 : check[0];
			check[1] = mstr->map[j][i][0] == -1 ? 1 : check[1];
		}
	}
	mstr->score_1 += check[0] ? 1 : 0;
	mstr->score_2 += check[1] ? 1 : 0;
	if (mstr->score_1 > mstr->score_2 + 1 || mstr->score_2 > mstr->score_1)
		mstr->updated = mstr->updated == 4 ? 2 : mstr->updated;
}


void			sub_parser_stockage(t_master *mstr)
{
	if (mstr->updated >= 2 && mstr->still_reading)
	{
		ft_parser_output_skimmer(mstr, mstr->size);
		if (mstr->still_reading)
			ft_check_score(mstr, mstr->size);
		else
		{
			mstr->color_1_g_tg = 0;
			mstr->color_2_g_tg = 0;
		}
		mstr->updated = mstr->updated == 2 ? 1 : mstr->updated;
	}
}
