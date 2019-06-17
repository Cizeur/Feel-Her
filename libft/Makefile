# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:01:34 by cgiron            #+#    #+#              #
#    Updated: 2019/06/17 12:18:44 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./dependancies_ft.mk

NAME = $(NAME_FT)
SRC_DIR := $(SRC_DIR_FT)
INC_DIR := $(INC_DIR_FT)
OBJ_DIR := $(OBJ_DIR_FT)
INCL	:= $(INC_FT)
SRC := $(SRC_FT)
OBJ := $(OBJ_FT)
DEPENDANCIES:= $(DEPENDANCIES_FT) 

CC      := gcc
CFLAGS  := $(SHARE_FLAGS)


.PHONY: all clean fclean re debug

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c $(DEPENDANCIES)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS)  -o $@ -c $<

$(NAME): $(OBJ) $(DEPENDANCIES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

debug: CFLAGS += $(SHARE_DEBUG)
debug: re clean

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
