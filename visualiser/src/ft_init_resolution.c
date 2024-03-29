/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:42:01 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:40:29 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"
#include "libft/libft.h"

void		ft_init_resolution(t_master *mstr, char **argv, int argc)
{
	if ((argc >= 2 && ft_atoi(argv[1]) == 0)
	|| (argc >= 3 && ft_atoi(argv[2]) == 0))
		ft_write_usage();
	if (YRES <= TOP_ROW_THICKNESS)
		ft_exit(FAIL_WINDOW_TO_SMALL, mstr);
	mstr->xres = argc >= 2 && ft_atoi(argv[1]) > 0 ? ft_atoi(argv[1]) : XRES;
	mstr->yres = argc == 2 && ft_atoi(argv[1]) > 0 ?
		ft_atoi(argv[1]) : YRES;
	mstr->yres = argc == 3 && ft_atoi(argv[2]) > 0 ?
	ft_atoi(argv[2]) : mstr->yres;
	mstr->xres = mstr->xres > MAX_XRES ? MAX_XRES : mstr->xres;
	mstr->yres = mstr->yres > MAX_YRES ? MAX_YRES : mstr->yres;
}
