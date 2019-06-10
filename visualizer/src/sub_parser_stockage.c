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

static void		ft_extract_player(t_master *mstr,char *line)
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

static int		ft_extract_line(t_master *mstr, char *line, int j)
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
		printf("%3d", mstr->map[j][i][0]);
	}
	printf("\n");
	return (i == mstr->size[1] ? 1 : 0);
}

static int		ft_read_map(t_master *mstr, int *size)
{
	int j;
	int check_line;
	int check;
	char *line;

	if (ft_line_jump(0, 1) <= 0)
		return (0);
	mstr->read_lines++;
	j = -1;
	check_line = 1;
	while (check_line && ++j < size[0] && (check = get_next_line(0, &line)) > 0)
	{
		mstr->read_lines++;
		check_line = ft_extract_line(mstr, line, j);
		free(line);
	}
	return (check_line && check > 0 ? 1 : 0);
}


static void		ft_find_map(t_master *mstr, int *size)
{
	char	*line;
	int		check;
	int		size_check;

	size_check = 1;
	mstr->fail_ind = 0;
	while (size_check && (check = get_next_line(0, &line)) > 0)
	{
		mstr->read_lines++;
		if (ft_strstr(line, LAUNCH_S))
			mstr->turn = 0;
		else if (ft_strstr(line, EXEC_1_S) || ft_strstr(line, EXEC_2_S))
			ft_extract_player(mstr, line);
		else if (ft_strstr(line, PLATEAU))
		{
			size_check = ft_check_size(line, size);
			if (size_check)
				size_check = ft_read_map(mstr,size);
			break;
		}
		free(line);
	}
	if (check <= 0)
		ft_exit(FAIL_READ_LINE, mstr);
	if (!size_check || size[0] <= 0)
		ft_exit(FAIL_LINE_LEN, mstr);
}

void			sub_parser_stockage(t_master *mstr)
{
	ft_find_map(mstr, mstr->size);
	printf("Map Size y: %d - x: %d\n", mstr->size[0], mstr->size[1]);
	printf("%s\n",mstr->player_1);
	printf("%s\n",mstr->player_2);
}
