/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_single_fd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:40:14 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/21 13:32:02 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*read_gnl(char **gnl, char *buf, int fd)
{
	char		*tmp;
	int			ret;

	ret = 1;
	while (!(ft_strchr(*gnl, '\n')) && ret)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret)
		{
			buf[ret] = '\0';
			tmp = *gnl;
			if (!(*gnl = ft_strjoin(*gnl, buf)))
				return (NULL);
			free(tmp);
		}
	}
	free(buf);
	return (*gnl);
}

static char		*stock_line(char **gnl)
{
	char		*buf;
	char		*newline;
	char		*tmp;

	buf = ft_strchr(*gnl, '\n');
	tmp = NULL;
	if (buf)
	{
		if (!(newline = ft_strndup(*gnl, buf - *gnl)))
			return (NULL);
		tmp = *gnl;
		if (!(*gnl = ft_strdup(buf + 1)))
			return (NULL);
		free(tmp);
	}
	else if (!(newline = ft_strdup(*gnl)))
		return (NULL);
	if (!(*gnl) || !tmp)
	{
		free(*gnl);
		*gnl = NULL;
	}
	return (newline);
}

int				get_next_line(const int fd, char **line)
{
	static char	*gnl[MAX_FD] = {0};
	char		*buf;

	if (fd < 0 || !line || BUFF_SIZE <= 0 || !(buf = ft_strnew(BUFF_SIZE + 1)) \
		|| read(fd, buf, 0) == -1 || (gnl[fd] == NULL
			&& !(gnl[fd] = ft_strnew(0))))
		return (-1);
	if (!(read_gnl(&(gnl[fd]), buf, fd)))
		return (-1);
	if (*(gnl[fd]))
	{
		if (!(*line = stock_line(&(gnl[fd]))))
			return (-1);
		return (1);
	}
	return (0);
}
