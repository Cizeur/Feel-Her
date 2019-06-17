# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 11:56:45 by cgiron            #+#    #+#              #
#    Updated: 2019/06/17 12:22:46 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./dependancies_champion.mk

NAME = $(NAME_FILL_CHAMPION)
SRC_DIR := $(SRC_DIR_FILL_CHAMPION)
INC_DIR := $(INC_DIR_FILL_CHAMPION)
OBJ_DIR := $(OBJ_DIR_FILL_CHAMPION)
INCL	:= $(INC_FILL_CHAMPION)
SRC := $(SRC_FILL_CHAMPION)
OBJ := $(OBJ_FILL_CHAMPION)
DEPENDANCIES:= $(DEPENDANCIES_FILL_CHAMPION)

L_FT    := ../libft
CC      := gcc
CFLAGS  := $(SHARE_FLAGS)
EXFLAGS	+= -L $(L_FT) -lft

.PHONY: all clean fclean re debug

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(DEPENDANCIES_FILL_CHAMPION_O)
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
