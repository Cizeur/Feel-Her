# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 09:46:01 by cgiron            #+#    #+#              #
#    Updated: 2019/06/17 12:20:18 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft/dependancies_ft.mk

L_VISU_FILL_DIR	:= visualiser

NAME_VISU_FILL	:= filler_visualiser

SRC_VISU_FILL = main.c\
	ft_define_error_check.c\
	ft_parser.c\
	ft_parser_check_size.c\
	ft_parser_output_skimmer.c\
	ft_parser_gnl.c\
	ft_parser_check_score.c\
	ft_parser_special_cases.c\
	ft_parser_map_update.c\
	ft_parser_player_get.c\
	ft_parser_heatmap.c\
	ft_init_resolution.c\
	ft_init_mstr.c\
	ft_write_usage.c\
	ft_exit.c\
	ft_window_init.c\
	ft_window_top_bar.c\
	ft_window_text_draw.c\
	ft_tracer.c\
	ft_tracer_grid_size.c\
	ft_tracer_grid.c\
	ft_tracer_grid_fill.c\
	ft_tracer_grid_heatmap_fill.c\
	ft_image_init.c\
	ft_image_background.c\
	ft_image_top_bar_bg.c\
	ft_image_line_trace.c\
	ft_image_draw_pixel.c\
	ft_image_dump.c\
	ft_color_gradient.c\
	ft_rgb.c\
	ft_refresh.c\
	ft_key_loop.c\
	ft_key_simple_press.c\
	ft_list_generate.c\
	ft_list_destroy.c\
	ft_chr_counter.c

SRC_DIR_VISU_FILL	:= src
INC_DIR_VISU_FILL	:= includes
OBJ_DIR_VISU_FILL	:= obj
INC_VISU_FILL		:= $(INC_DIR_VISU_FILL)/filler_visualiser.h\
				$(INC_DIR_VISU_FILL)/libft/libft.h
OBJ_VISU_FILL		:= $(addprefix $(OBJ_DIR_VISU_FILL)/,$(SRC_VISU_FILL:.c=.o))
SRC_VISU_FILL_F		:= $(addprefix $(SRC_DIR_VISU_FILL)/,$(SRC_VISU_FILL))

DEPENDANCIES_VISU_FILL		:= Makefile $(INC_VISU_FILL) ./dependancies_visu.mk
DEPENDANCIES_VISU_FILL		+= $(addprefix ../,$(DEPENDANCIES_FT_EXPORT))
DEPENDANCIES_VISU_FILL_F 	:= $(DEPENDANCIES_FT) $(SRC_VISU_FILL_F)

SHARE_FLAGS			:= -Wall -Wextra -Werror -O3 -ffreestanding -fno-builtin
SHARE_FLAGS			+= -I $(INC_DIR_VISU_FILL)
SHARE_DEBUG			:= -O0 -g
SHARE_FLAGS_VISU_FILL_EXPORT	:= -I $(addprefix $(L_VISU_FILL_DIR)/,$(INC_DIR_VISU_FILL))
DEPENDANCIES_VISU_FILL_EXPORT	:= $(addprefix $(L_VISU_FILL_DIR)/,$(DEPENDANCIES_VISU_FILL_F))
