# **********************************V****************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 10:25:47 by cgiron            #+#    #+#              #
#    Updated: 2019/06/17 12:19:58 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./dependancies_visu.mk

NAME = $(NAME_VISU_FILL)
SRC_DIR := $(SRC_DIR_VISU_FILL)
INC_DIR := $(INC_DIR_VISU_FILL)
OBJ_DIR := $(OBJ_DIR_VISU_FILL)
INCL	:= $(INC_VISU_FILL)
SRC := $(SRC_VISU_FILL)
OBJ := $(OBJ_VISU_FILL)
DEPENDANCIES:= $(DEPENDANCIES_VISU_FILL)

L_FT    := ../libft

CC      := gcc
CFLAGS  := $(SHARE_FLAGS)
EXFLAGS	+= -lmlx -framework OpenGL -framework AppKit
EXFLAGS	+= -L $(L_FT) -lft

.PHONY: all clean fclean re debug

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(DEPENDANCIES_VISU_FILL_O)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS)  -o $@ -c $<

$(NAME): $(OBJ) $(DEPENDANCIES)
	$(MAKE) -C $(L_FT) "CFLAGS=$(CFLAGS)" --no-print-directory
	$(CC)  $(EXFLAGS)  $(OBJ) -o $(NAME)

clean:
	$(MAKE) clean -C $(L_FT) --no-print-directory
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(L_FT) --no-print-directory
	rm -f $(NAME)

debug: CFLAGS += $(SHARE_DEBUG)
debug: re clean

re: fclean all
