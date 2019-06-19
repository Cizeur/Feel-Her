/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:20:08 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:42:02 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"
#include <mlx.h>

void		ft_window_init(void **mem_ptr, t_master *mstr)
{
	mem_ptr[MLX_PTR] = mlx_init();
	if (!(mem_ptr[WIN_PTR] = mlx_new_window(mem_ptr[MLX_PTR],
	mstr->xres, mstr->yres, "Filler")))
		ft_exit(FAIL_WINDOW_CREATION, mstr);
	mem_ptr[I_PTR] = NULL;
	mem_ptr[I_ADR] = NULL;
}
