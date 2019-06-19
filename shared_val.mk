# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    share_flags.mk                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 09:36:56 by cgiron            #+#    #+#              #
#    Updated: 2019/06/19 17:20:52 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHARE_SRC_DIR			:= src
SHARE_OBJ_DIR			:= obj
SHARE_INC_DIR			:= includes

vpath %.c $(SHARE_SRC_DIR)
vpath %.h $(SHARE_INC_DIR)
vpath %.o $(SHARE_OBJ_DIR)

SHARE_FLAGS				:= -Wall -Wextra -Werror -O3 -ffreestanding -fno-builtin
SHARE_FLAGS				+= -I $(SHARE_INC_DIR) -flto
SHARE_DEBUG				:= -O0 -g
