# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:16:41 by cgiron            #+#    #+#              #
#    Updated: 2019/06/17 12:16:43 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./champion/dependancies_champion.mk
include ./visualiser/dependancies_visu.mk
include ./libft/dependancies_ft.mk

NAME = $(NAME_FILL_CHAMPION) $(NAME_VISU_FILL)

.PHONY: all clean fclean re debug

C_NAME = "NAME_FILL_CHAMPION=../$(NAME_FILL_CHAMPION)"
V_NAME = "NAME_VISU_FILL=../$(NAME_VISU_FILL)"
DEPENDANCIES = $(DEPENDANCIES_FT_EXPORT) Makefile

all : $(NAME) 

$(NAME_FILL_CHAMPION) : $(DEPENDANCIES_FILL_CHAMPION_EXPORT) $(DEPENDANCIES)
	$(MAKE) -C $(L_FILL_CHAMPION_DIR) $(C_NAME) --no-print-directory
$(NAME_VISU_FILL) : $(DEPENDANCIES_VISU_FILL_EXPORT) $(DEPENDANCIES)
	$(MAKE) -C $(L_VISU_FILL_DIR) $(V_NAME) --no-print-directory

clean:
	$(MAKE) clean -C $(L_FT_DIR) --no-print-directory
	$(MAKE) clean -C $(L_FILL_CHAMPION_DIR) --no-print-directory
	$(MAKE) clean -C $(L_VISU_FILL_DIR) --no-print-directory
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C	$(L_FT_DIR) --no-print-directory
	$(MAKE) fclean -C	$(L_FILL_CHAMPION_DIR) --no-print-directory
	$(MAKE) fclean -C	$(L_VISU_FILL_DIR) --no-print-directory
	rm -f	$(L_FILL_CHAMPION_DIR)/$(NAME_FILL_CHAMPION)
	rm -f	$(L_VISU_FILL_DIR)/$(NAME_VISU_FILL)
	rm -f 	$(NAME)

debug:
	$(MAKE) debug -C	$(L_FT_DIR) --no-print-directory
	$(MAKE) debug -C	$(L_FILL_CHAMPION_DIR) --no-print-directory
	$(MAKE) debug -C	$(L_VISU_FILL_DIR) --no-print-directory

show:
	echo $(DEPENDANCIES_VISU_FILL_EXPORT)


re: fclean all