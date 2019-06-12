/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:53:06 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/15 10:54:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"


int				ft_key_loop(int key, t_master *mstr)
{
	mstr->updated = key == SPACEBAR ? 2 : mstr->updated;
	if (mstr->updated)
		ft_refresh(mstr);
	return(key);
}
