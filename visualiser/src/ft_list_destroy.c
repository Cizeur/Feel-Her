/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:36:29 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 17:36:33 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void		ft_list_destroy(t_list **output)
{
	t_list *stock;

	while (*output)
	{
		stock = (*output)->next;
		if ((*output)->content)
		{
			free((*output)->content);
			(*output)->content = NULL;
		}
		(*output)->content_size = 0;
		free(*output);
		*output = stock;
	}
}
