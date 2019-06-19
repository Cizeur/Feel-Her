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

include ./dependancies_visualiser.mk

DEPENDANCY_OBJ_INC_FILE := ./dependancies_$(L_VISUALISER_DIR)_object.mk
L_FT    := ../libft
EXFLAGS := -L $(L_FT) -lft
EXFLAGS	+= -lmlx -framework OpenGL -framework AppKit

NAME 	:= $(NAME_VISUALISER)
SRC_DIR := $(SHARE_SRC_DIR)
INC_DIR := $(SHARE_INC_DIR)
OBJ_DIR := $(SHARE_OBJ_DIR)
SRC 	:= $(SRC_VISUALISER)
OBJ		:= $(patsubst %.c,%.o,$(SRC))
DEPENDANCIES:= $(DEPENDANCIES_VISUALISER)
CC      := gcc
CFLAGS  := $(SHARE_FLAGS)

.PHONY: all clean fclean re debug

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o:%.c $(DEPENDANCIES_VISUALISER_O)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

-include $(DEPENDANCY_OBJ_INC_FILE)

$(NAME): $(OBJ) $(DEPENDANCIES)
	$(MAKE) -C $(L_FT) "CFLAGS=$(CFLAGS)" --no-print-directory
	$(CC)  $(EXFLAGS)  $(addprefix $(OBJ_DIR)/,$(OBJ)) -o $(NAME)

clean:
	$(MAKE) clean -C $(L_FT) --no-print-directory
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(L_FT) --no-print-directory
	rm -f $(NAME)

debug: CFLAGS += $(SHARE_DEBUG)
debug: re clean

re: fclean all
