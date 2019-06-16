/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_get_next_line.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:08:46 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 15:08:47 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

int 					ft_parser_gnl(t_master *mstr, char  *line)
{
	char *pos;
	char *bufferpos;

	ft_bzero(line, BUFFER_LINE);
	bufferpos = mstr->buffer_pos;
	if (!bufferpos && !(mstr->still_reading = 0))
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