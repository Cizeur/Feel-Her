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
	ft_init_resolution.c\
	ft_init_mstr.c\
	ft_write_usage.c\
	ft_exit.c\
	ft_key_simple_press.c\
	ft_init_window.c\
	ft_grid_size.c\
	ft_image_fresh.c\
	ft_rgb.c\
	ft_grid_trace.c\
	ft_line_trace.c\
	ft_draw_pixel.c\
	ft_image_dump.c\
	ft_text_draw.c\
	ft_refresh.c\
	ft_image_background.c\
	ft_grid_fill.c\
	ft_key_loop.c\
	ft_color_gradient.c\
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
