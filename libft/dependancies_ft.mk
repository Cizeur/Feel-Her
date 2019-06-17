# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 09:46:01 by cgiron            #+#    #+#              #
#    Updated: 2019/06/17 12:19:08 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

L_FT_DIR	:= libft

NAME_FT	:= libft.a

SRC_FT = ft_memset.c \
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
	  ft_atoi_base.c\
	  ft_swap.c

SRC_DIR_FT	:= src
INC_DIR_FT	:= includes
OBJ_DIR_FT	:= obj
INC_FT		:= $(INC_DIR_FT)/libft.h\
			$(INC_DIR_FT)/get_next_line.h
OBJ_FT		:= $(addprefix $(OBJ_DIR_FT)/,$(SRC_FT:.c=.o))
SRC_FT_F	:= $(addprefix $(SRC_DIR_FT)/,$(SRC_FT))

DEPENDANCIES_FT			:= Makefile $(INC_FT) ./dependancies_ft.mk 
DEPENDANCIES_FT_F 		:= $(DEPENDANCIES_FT) $(SRC_FT_F)

SHARE_FLAGS				:= -Wall -Wextra -Werror -O3 -ffreestanding -fno-builtin
SHARE_FLAGS				+= -I $(INC_DIR_FT)
SHARE_DEBUG				:= -O0 -g
DEPENDANCIES_FT_EXPORT	:= $(addprefix $(L_FT_DIR)/,$(DEPENDANCIES_FT_F))
