/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 08:43:17 by cgiron            #+#    #+#             */
/*   Updated: 2019/05/21 10:06:30 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
 
void	hook_loops(t_master *mstr)
{
	mlx_key_hook((mstr->mem_ptr)[WIN_PTR], ft_key_simple_press, mstr);
//	mlx_hook((mstr->mem_ptr)[WIN_PTR], 2, 0, ft_key_loop, mstr);
//	mlx_hook((mstr->mem_ptr)[WIN_PTR], 4, 0, ft_mouse_pressed, mstr);
//	mlx_hook((mstr->mem_ptr)[WIN_PTR], 5, 0, ft_mouse_released, mstr);
//	mlx_hook((mstr->mem_ptr)[WIN_PTR], 6, 0, ft_mouse_moved, mstr);
}

int		main(int argc, char **argv)
{
	int			i;
	char		*line;
	t_master	*mstr;
	t_master	mstr_val;
	int pos[2];

	mstr = &mstr_val;
	i = 0;
	line = 0;
	ft_init_mstr(mstr);
	ft_init_resolution(mstr, argv, argc);
	if (argc < 1 || argc > 3)
		ft_write_usage();
	else
	{
		sub_parser_stockage(mstr);
		ft_grid_size(mstr, mstr->size);
		printf("tc x: %d - tc y: %d\n", mstr->top_corner[1], mstr->top_corner[0]);
		printf("x: %d - y: %d\n", mstr->mult_x, mstr->mult_y);
		ft_init_window(mstr->mem_ptr, mstr);
		ft_image_fresh(mstr->mem_ptr, mstr);
		ft_grid_trace(mstr, mstr->size);
		mlx_string_put (mstr->mem_ptr[MLX_PTR], mstr->mem_ptr[WIN_PTR], 0 ,0 , 255, "bonjour");
		ft_image_dump(mstr->mem_ptr);
		ft_text_draw(mstr,pos, 255, mstr->player_1);
		hook_loops(mstr);
		mlx_loop((mstr->mem_ptr)[MLX_PTR]);
	}
	return (0);
}
