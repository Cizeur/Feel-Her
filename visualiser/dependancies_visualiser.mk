# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 09:46:01 by cgiron            #+#    #+#              #
#    Updated: 2019/06/17 17:19:22 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

-include ../libft/dependancies_libft.mk
-include ../shared_val.mk
-include ./shared_val.mk

L_VISUALISER_DIR	:= visualiser

NAME_VISUALISER	:= filler_visualiser

SRC_VISUALISER = main.c\
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

INC_VISUALISER					:= filler_visualiser.h libft/get_next_line.h libft/libft.h

DEPENDANCIES_VISUALISER_O		:= Makefile ./dependancies_$(L_VISUALISER_DIR).mk\
								 ./dependancies_$(L_VISUALISER_DIR)_object.mk\
								 ../shared_val.mk
DEPENDANCIES_VISUALISER			:= $(DEPENDANCIES_VISUALISER_O) \
 								$(addprefix ../,$(DEPENDANCIES_LIBFT_EXPORT))

INC_VISUALISER_EXPORT			:= $(addprefix $(SHARE_INC_DIR)/,$(INC_VISUALISER))
SRC_VISUALISER_EXPORT			:= $(addprefix $(SHARE_SRC_DIR)/,$(SRC_VISUALISER))
DEPENDANCIES_VISUALISER_E 		:= $(DEPENDANCIES_VISUALISER) $(SRC_VISUALISER_EXPORT) $(INC_VISUALISER_EXPORT)
DEPENDANCIES_VISUALISER_EXPORT	:= $(addprefix $(L_VISUALISER_DIR)/,$(DEPENDANCIES_VISUALISER_E))
