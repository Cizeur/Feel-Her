/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 14:19:25 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/19 15:46:26 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"
#include <mlx.h>

void			ft_image_init(void **mem_ptr, t_master *mstr)
{
	int data_prm[3];

	mem_ptr[I_PTR] = mlx_new_image(mem_ptr[MLX_PTR], mstr->xres, mstr->yres);
	if (!mem_ptr[I_PTR])
		ft_exit(FAIL_IMAGE_CREATION, mstr);
	mem_ptr[I_ADR] = mlx_get_data_addr(mem_ptr[I_PTR],
			&(data_prm[0]), &(data_prm[1]), &(data_prm[2]));
}
