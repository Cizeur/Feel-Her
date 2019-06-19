/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_gnl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:37:02 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 17:37:05 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

int				ft_parser_gnl(t_master *mstr, char *line)
{
	char *pos;
	char *bufferpos;

	ft_bzero(line, BUFFER_LINE);
	bufferpos = mstr->buffer_pos;
	if (!bufferpos && !(mstr->still_reading = 0))
		return (0);
	while (bufferpos && !(pos = ft_strchr(bufferpos, '\n')))
	{
		if (ft_strlen(line) + ft_strlen(bufferpos) > BUFFER_LINE)
			ft_exit(FAIL_LINE_TO_LONG, mstr);
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
	mstr->current_line = line;
	mstr->read_lines++;
	return (1);
}
