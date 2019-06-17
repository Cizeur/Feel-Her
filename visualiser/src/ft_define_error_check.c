/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 08:38:22 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/17 08:38:24 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void			ft_define_error_check(t_master *mstr)
{
	if (BUFFER_LINE != (2 * BUFFER_READ) + 1)
		ft_putstr("\e[31mPlease keep BUFFER_LINE at (2 * BUFFER_READ) + 1)\e[39m\n");
	else if (BUFFER_READ <= 0)
		ft_putstr("\e[31mKeep BUFFER_READ strictly positif\e[31m\n");
	else if (XRES <= 0 || YRES <= 0 || MAX_XRES <= 0 || MAX_YRES <= 0)
		ft_putstr("\e[31mRES defines should be strictly positive\e[31m\n");
	else if (FILL_PERCENT <= 0 || FILL_PERCENT > 100)
		ft_putstr("\e[31mFILL_PERCENT between 1 and 100\e[31m\n");
	else
		return;
	ft_exit(FAIL_BAD_DEFINES, mstr);
}