# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 09:01:34 by cgiron            #+#    #+#              #
#    Updated: 2019/06/10 09:14:20 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCL = ./includes/libft.h\
	   ./includes/get_next_line.h

SRC_DIR := ./src_libft
INC_DIR := ./includes
OBJ_DIR := ./obj_libft
INCL := $(INC_DIR)/get_next_line.h\
$(INC_DIR)/get_next_line.h\

SRC = ft_memset.c \
	  ft_bzero.c \
	  ft_memcpy.c \
	  ft_memccpy.c \
	  ft_memmove.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_strlen.c \
	  ft_strdup.c \
	  ft_strcpy.c \
	  ft_strncpy.c \
	  ft_strcat.c \
	  ft_strncat.c \
	  ft_strlcat.c \
	  ft_strchr.c \
	  ft_strrchr.c\
	  ft_strstr.c\
	  ft_strnstr.c\
	  ft_strcmp.c\
	  ft_strncmp.c\
	  ft_atoi.c\
	  ft_isalpha.c\
	  ft_isdigit.c\
	  ft_isalnum.c\
	  ft_isascii.c\
	  ft_isprint.c\
	  ft_toupper.c\
	  ft_tolower.c\
	  ft_memalloc.c\
	  ft_memdel.c\
	  ft_strnew.c\
	  ft_strdel.c\
	  ft_strclr.c\
	  ft_striter.c\
	  ft_striteri.c\
	  ft_strmap.c\
	  ft_strmapi.c\
	  ft_strequ.c\
	  ft_strnequ.c\
	  ft_strsub.c\
	  ft_strjoin.c\
	  ft_strtrim.c\
	  ft_strsplit.c\
	  ft_itoa.c\
	  ft_putchar.c\
	  ft_putstr.c\
	  ft_putendl.c\
	  ft_putnbr.c\
	  ft_putchar_fd.c\
	  ft_putstr_fd.c\
	  ft_putendl_fd.c\
	  ft_putnbr_fd.c\
	  ft_lstnew.c\
	  ft_lstdelone.c\
	  ft_lstdel.c\
	  ft_lstadd.c\
	  ft_lstiter.c\
	  ft_lstmap.c\
	  ft_printbits.c\
	  ft_strrev.c\
	  ft_tab_strrev.c\
	  ft_tab_strsort.c\
	  ft_strswap.c\
	  ft_strsplitn.c\
	  ft_strnjoin.c\
	  ft_strndup.c\
	  ft_max.c\
	  ft_min.c\
	  ft_sqweeze.c\
	  ft_newstrtab.c\
	  ft_strtabdel.c\
	  ft_abs.c\
	  ft_power.c\
	  ft_split_whitespace.c\
	  ft_split_whitespace_len.c\
	  ft_lstaddend.c\
	  ft_tab_len.c\
	  get_next_line.c\
	  ft_atoi_base.c

OBJ     := $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

CC      := gcc
CFLAGS  := -Wall -Wextra -Werror -O3 -ffreestanding -fno-builtin

L_FT    := ./lib/$(LIB_DIR)

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

%.o : $(SRC_DIR)/%.c Makefile $(INCL)	
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -o $(OBJ_DIR)/$@ -c $<

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c Makefile $(INCL)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR)  -o $@ -c $<

$(NAME): $(OBJ) Makefile $(INCL)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
