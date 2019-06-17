/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 08:24:14 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/20 10:50:35 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler_visualiser.h"


static void		ft_free_all(t_master *mstr)
{
	ft_list_destroy(&(mstr->output));
	mstr->current = NULL;
	if ((mstr->mem_ptr)[WIN_PTR] && (mstr->mem_ptr)[MLX_PTR])
		mlx_destroy_window((mstr->mem_ptr)[MLX_PTR], (mstr->mem_ptr)[WIN_PTR]);
	if ((mstr->mem_ptr)[MLX_PTR] && (mstr->mem_ptr)[I_PTR])
		mlx_destroy_image(mstr->mem_ptr[MLX_PTR], mstr->mem_ptr[I_PTR]);
	if (mstr->player_1)
		ft_memdel((void**)&(mstr->player_1));
	if (mstr->player_2)
		ft_memdel((void**)&(mstr->player_2));
}

void			ft_exit(int code, t_master *mstr)
{
	if (mstr)
		ft_free_all(mstr);
	ft_putstr("\r");
	if (code == STANDARD_EXIT)
		exit(0);
	exit(1);
}
