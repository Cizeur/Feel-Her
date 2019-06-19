# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies_object.mk                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 10:11:30 by cgiron            #+#    #+#              #
#    Updated: 2019/06/19 11:26:13 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_parser_alloc_double_array.o: filler.h libft/libft.h
ft_parser_get_arrays.o: filler.h libft/get_next_line.h libft/libft.h
ft_parser_get_dims.o: filler.h libft/libft.h libft/get_next_line.h
ft_parser_get_player.o: filler.h libft/libft.h libft/get_next_line.h
ft_solver_check_score.o: filler.h
ft_solver_heatmap.o: filler.h libft/libft.h
ft_solver_tab_skim.o: filler.h
main.o: filler.h libft/libft.h
parser.o: filler.h libft/libft.h
sub_solver.o: filler.h
