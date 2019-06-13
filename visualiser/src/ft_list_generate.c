/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_generate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 14:42:01 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/11 14:42:21 by cgiron           ###   ########.fr       */
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
		mstr->read_lines += r;
		output = ft_lstaddend(output, buffer, ft_strlen(buffer) + 1);
		if (output)
			mstr->output = output;
		else
			ft_exit(FAIL_LISTING, mstr);
		ft_bzero(buffer, BUFFER_READ + 1);
	}
	if (r == -1)
		ft_exit(FAIL_LISTING, mstr);
	printf("nombre de carac - %d\n\n", mstr->read_lines);
	mstr->read_lines = 0;
	mstr->current = mstr->output;
	mstr->buffer_pos = (char *)mstr->current->content;
}
