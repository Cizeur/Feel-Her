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

include ./dependancies_libft.mk
-include ../shared_val.mk
-include ./shared_val.mk

DEPENDANCY_OBJ_INC_FILE := ./dependancies_$(L_LIBFT_DIR)_object.mk

NAME 	:= $(NAME_LIBFT)
SRC_DIR := $(SHARE_SRC_DIR)
INC_DIR := $(SHARE_INC_DIR)
OBJ_DIR := $(SHARE_OBJ_DIR)
SRC 	:= $(SRC_LIBFT)
OBJ		:= $(patsubst %.c,%.o,$(SRC))
DEPENDANCIES:= $(DEPENDANCIES_LIBFT)

CC      := gcc
CFLAGS  := $(SHARE_FLAGS)

.PHONY: all clean fclean re debug

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o:%.c $(DEPENDANCIES_LIBFT)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $(OBJ_DIR)/$@

-include $(DEPENDANCY_OBJ_INC_FILE)

$(NAME): $(OBJ)
	ar rc $(NAME) $(addprefix $(OBJ_DIR)/,$(OBJ))
	ranlib $(NAME)

debug: CFLAGS += $(SHARE_DEBUG)
debug: re clean

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
