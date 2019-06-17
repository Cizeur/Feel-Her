# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    dependancies.mk                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:56:11 by cgiron            #+#    #+#              #
#    Updated: 2019/06/17 13:51:38 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft/dependancies_ft.mk

L_FILL_CHAMPION_DIR	:= champion

NAME_FILL_CHAMPION	:= cgiron-yforeau.filler

SRC_FILL_CHAMPION =  ft_parser_alloc_double_array.c\
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

SRC_DIR_FILL_CHAMPION	:= src
INC_DIR_FILL_CHAMPION	:= includes
OBJ_DIR_FILL_CHAMPION	:= obj
INC_FILL_CHAMPION		:= $(INC_DIR_FILL_CHAMPION)/c_colors.h\
				$(INC_DIR_FILL_CHAMPION)/libft/libft.h
OBJ_FILL_CHAMPION		:= $(addprefix $(OBJ_DIR_FILL_CHAMPION)/,$(SRC_FILL_CHAMPION:.c=.o))
SRC_FILL_CHAMPION_F		:= $(addprefix $(SRC_DIR_FILL_CHAMPION)/,$(SRC_FILL_CHAMPION))

DEPENDANCIES_FILL_CHAMPION		:= Makefile $(INC_FILL_CHAMPION) ./dependancies_champion.mk
DEPENDANCIES_FILL_CHAMPION		+= $(addprefix ../,$(DEPENDANCIES_FT_EXPORT))
DEPENDANCIES_FILL_CHAMPION_F 	:= $(DEPENDANCIES_FT) $(SRC_FILL_CHAMPION_F)

SHARE_FLAGS			:= -Wall -Wextra -Werror -O3 -ffreestanding -fno-builtin
SHARE_FLAGS			+= -I $(INC_DIR_FILL_CHAMPION)
SHARE_DEBUG			:= -O0 -g
SHARE_FLAGS_FILL_CHAMPION_EXPORT	:= -I $(addprefix $(L_FILL_CHAMPION_DIR)/,$(INC_DIR_FILL_CHAMPION))
DEPENDANCIES_FILL_CHAMPION_EXPORT	:= $(addprefix $(L_FILL_CHAMPION_DIR)/,$(DEPENDANCIES_FILL_CHAMPION_F))
