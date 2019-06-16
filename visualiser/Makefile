# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 10:25:47 by cgiron            #+#    #+#              #
#    Updated: 2019/06/12 15:29:14 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../filler_visualiser

SRC_DIR := ./src
INC_DIR := ./includes
OBJ_DIR := ./obj
INCL := $(INC_DIR)/filler_visualiser.h

L_FT    := ./libft
L_MLX	:= ./mlx

SRC := main.c\
	sub_parser_stockage.c\
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
	ft_list_generate.c

OBJ     := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC      := gcc
CFLAGS  := -Wall -Wextra -Werror
CFLAGS  += -O3 -ffreestanding -fno-builtin
EXFLAGS	+= -lmlx -framework OpenGL -framework AppKit
#EXFLAGS += -L $(L_MLX) -I $(L_MLX)
EXFLAGS	+= -L $(L_FT) -lft


.PHONY: all clean fclean re debug

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o : $(SRC_DIR)/%.c Makefile $(INCL)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $(OBJ_DIR)/$@ -c $<

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c Makefile $(INCL)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) $(LIBFLAGS) -o $@ -c $<

$(NAME): $(OBJ) Makefile $(INCL)
	$(MAKE) -C $(L_FT) --no-print-directory
	#$(MAKE) -C $(L_MLX) --no-print-directory
	$(CC)  $(EXFLAGS)  $(OBJ) -o $(NAME)

clean:
	$(MAKE) clean -C $(L_FT) --no-print-directory
	#$(MAKE) clean -C $(L_MLX) --no-print-directory
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(L_FT) --no-print-directory
	rm -f $(NAME)

re: fclean all
