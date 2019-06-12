/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 10:48:33 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/15 15:36:09 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"

void		ft_init_window(void **mem_ptr, t_master *mstr)
{
	mem_ptr[MLX_PTR] = mlx_init();
	if (!(mem_ptr[WIN_PTR] = mlx_new_window(mem_ptr[MLX_PTR],
	mstr->xres, mstr->yres, "Filler")))
		ft_exit(FAIL_WINDOW_CREATION, mstr);
	mem_ptr[I_PTR] = NULL;
	mem_ptr[I_ADR] = NULL;
}
