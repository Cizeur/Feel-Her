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

#include "fdf.h"
/* 
static int		ft_line_jump(int fd, int nb_lines)
{
	char *line;
	int r;
	int actual_lines;

	r = 1;
	actual_lines = nb_lines;
	if (nb_lines < 0)
		return (-1);
	while (actual_lines && (r = get_next_line(fd,&line) >= 0))
	{
		actual_lines--;
		free(line);
	}
	return (r < 0 ? -1 : nb_lines - actual_lines);
}
*/

static int		ft_check_size(char *line, int *size)
{
	char *number;
	if (size[0] != -1 && size[1] != -1)
		return (1);
	if (!(number = ft_strchr(line,' ')) || ft_atoi(number + 1) <= 0)
		return (0);
	size[0] = ft_atoi(number + 1);
	*number = '|';
	if (!(number = ft_strchr(line,' ')) || ft_atoi(number + 1) <= 0)
		return (0);
	size[1] = ft_atoi(number + 1);
	return(1);
}

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

t_list			*ft_line_find(t_list *current, char  *line)
{
	char *pos;

	if (!current)
		return (NULL);
	ft_bzero(line, MAX_XRES * 2 + 1);
	if((pos = ft_strchr(current->content, '\n')))
	{	
		*pos = 0;
		ft_strcpy(line, current->content);
		ft_memmove(current->content, pos + 1, (int)(pos + 1 - (char *)current->content));
		return (current);
	}
	else
	{
		if (current->next)
		{
			ft_strcpy(line, current->content);
			if((pos = ft_strchr(current->next->content, '\n')))
			{	
				*pos = 0;
				ft_strjoin(line, current->next->content);
				ft_memmove(current->next->content, pos + 1,
				(int)(pos + 1 - (char *)current->next->content));
			}
			else
				ft_strjoin(line, current->next->content);
		}
		else
			ft_strcpy(line, current->content);
	}
	return(current->next);

}

static int		ft_line_extract(t_master *mstr, char *line, int j)
{
	char *start;
	int *pos;
	int i;

	if (!(start = ft_strchr(line, ' ')))
		return (0);
	start++;
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

static int		ft_map_extract(t_master *mstr, int *size)
{
	int j;
	int check_line;
	char	line[2 * MAX_XRES + 1];

	mstr->current = ft_line_find(mstr->current, line);
	if (!mstr->current)
		return(-1);
	mstr->read_lines++;
	j = -1;
	check_line = 1;
	while (check_line && ++j < size[0] &&
		(mstr->current = ft_line_find(mstr->current, line)))
	{
		mstr->read_lines++;
		check_line = ft_line_extract(mstr, line, j);
		mstr->current = mstr->current->next;
	}
	return (check_line && mstr->current ? 1 : 0);
}


static void		ft_map_find_extract(t_master *mstr, int *size)
{
	char	line[2 * MAX_XRES + 1];
	int		size_check;

	size_check = 1;
	mstr->fail_ind = 0;
	while (size_check && (mstr->current = ft_line_find(mstr->current, line)))
	{
		printf("%s", line);
		mstr->read_lines++;
		if (ft_strstr(line, LAUNCH_S))
			mstr->turn = 0;
		else if (ft_strstr(line, EXEC_1_S) || ft_strstr(line, EXEC_2_S))
			ft_player_extract(mstr, line);
		else if (ft_strstr(line, PLATEAU))
		{
			size_check = ft_check_size(line, size);
			if (size_check)
				size_check = ft_map_extract(mstr,size);
			break;
		}
	}
	if (!mstr->current)
		ft_exit(FAIL_READ_LINE, mstr);
	if (!size_check || size[0] <= 0)
		ft_exit(FAIL_LINE_LEN, mstr);
}

void			sub_parser_stockage(t_master *mstr)
{

		ft_bzero(mstr->amp_o, sizeof(int) * 3);
		ft_bzero(mstr->amp_x, sizeof(int) * 3);
		ft_map_find_extract(mstr, mstr->size);
		//printf("Map Size y: %d - x: %d\n", mstr->size[0], mstr->size[1]);
	//	printf("amplitudes x - %d - %d - %d\n", mstr->amp_x[0], mstr->amp_x[1], mstr->amp_x[2]);
	//	printf("amplitudes o - %d - %d - %d\n", mstr->amp_o[0], mstr->amp_o[1], mstr->amp_o[2]);
	//	printf("%s\n",mstr->player_1);
	//	printf("%s\n",mstr->player_2);
		mstr->updated = 0;
}
