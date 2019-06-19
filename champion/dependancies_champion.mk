# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:56:11 by cgiron            #+#    #+#              #
#    Updated: 2019/06/19 17:04:37 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft/dependancies_libft.mk
-include ../shared_val.mk
-include ./shared_val.mk

ifeq ($(SHARE_SRC_DIR),)
$(error SHARE_VAL not included)
endif

L_CHAMPION_DIR	:= champion

NAME_CHAMPION	:= cgiron-yforeau.filler

SRC_CHAMPION =  \
	ft_parser_alloc_double_array.c\
	ft_parser_free_double_array.c\
	ft_parser_get_arrays.c\
	ft_parser_get_dims.c\
	ft_parser_get_player.c\
	ft_solver_check_score.c\
	ft_solver_heatmap.c\
	ft_solver_tab_skim.c\
	main.c\
	parser.c\
	sub_solver.c\

INC_CHAMPION					:= filler.h libft/get_next_line.h libft/libft.h

DEPENDANCIES_CHAMPION_O			:= Makefile ./dependancies_$(L_CHAMPION_DIR).mk\
								 ./dependancies_$(L_CHAMPION_DIR)_object.mk\
								 ../shared_val.mk
DEPENDANCIES_CHAMPION			:= $(DEPENDANCIES_CHAMPION_O) \
 								$(addprefix ../,$(DEPENDANCIES_LIBFT_EXPORT))

INC_CHAMPION_EXPORT				:= $(addprefix $(SHARE_INC_DIR)/,$(INC_CHAMPION))
SRC_CHAMPION_EXPORT				:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_CHAMPION))
DEPENDANCIES_CHAMPION_E 		:= $(DEPENDANCIES_CHAMPION) $(SRC_CHAMPION_EXPORT) $(INC_CHAMPION_EXPORT)
DEPENDANCIES_CHAMPION_EXPORT	:= $(addprefix $(L_CHAMPION_DIR)/,$(DEPENDANCIES_CHAMPION_E))
