/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_generate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:42:01 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 12:03:12 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void	ft_list_generate(t_master *mstr)
{
	int		r;
	t_list	*output;
	char 	buffer[BUFFER_READ + 1];

	output = NULL;
	ft_bzero(buffer, BUFFER_READ + 1);
	mstr->read_lines = 0;
	while((r = read(0, buffer, BUFFER_READ)) > 0)
	{
		output = ft_lstaddend(output, buffer, ft_strlen(buffer) + 1);
		if (output)
			mstr->output = output;
		else
			ft_exit(FAIL_LISTING, mstr);
		mstr->read_lines += ft_chr_counter(buffer, '\n');
		ft_bzero(buffer, BUFFER_READ + 1);
	}
	if (r == -1 || !mstr->read_lines)
		ft_exit(r == -1 ? FAIL_READING : FAIL_SINGLE_LINE, mstr);
	mstr->read_lines = 0;
	mstr->current = mstr->output;
	mstr->buffer_pos = (char *)mstr->current->content;
}
