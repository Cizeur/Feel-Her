# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/17 12:16:41 by cgiron            #+#    #+#              #
#    Updated: 2019/06/19 16:21:58 by cgiron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./champion/dependancies_champion.mk
include ./visualiser/dependancies_visualiser.mk
include ./libft/dependancies_libft.mk

NAME := $(NAME_CHAMPION) $(NAME_VISUALISER)

.PHONY: all clean fclean re debug

C_NAME = "NAME_CHAMPION=../$(NAME_CHAMPION)"
V_NAME = "NAME_VISUALISER=../$(NAME_VISUALISER)"

all : $(NAME)

STD_DEPENDANCY := $(DEPENDANCIES_LIBFT_EXPORT)

$(NAME_CHAMPION) :  $(DEPENDANCIES_CHAMPION_EXPORT) $(STD_DEPENDANCY)
	@$(MAKE) -C $(L_CHAMPION_DIR) $(C_NAME) --no-print-directory

$(NAME_VISUALISER) : $(DEPENDANCIES_VISUALISER_EXPORT) $(STD_DEPENDANCY)
	@$(MAKE) -C $(L_VISUALISER_DIR) $(V_NAME) --no-print-directory

clean:
	$(MAKE) clean -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) clean -C $(L_CHAMPION_DIR) --no-print-directory
	$(MAKE) clean -C $(L_VISUALISER_DIR) --no-print-directory

fclean:
	$(MAKE) fclean -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) fclean -C $(L_CHAMPION_DIR) --no-print-directory
	$(MAKE) fclean -C $(L_VISUALISER_DIR) --no-print-directory
	rm -f $(L_CHAMPION_DIR)/$(NAME_CHAMPION)
	rm -f $(L_VISUALISER_DIR)/$(NAME_VISUALISER)
	rm -f $(NAME)

debug:
	$(MAKE) debug -C $(L_LIBFT_DIR) --no-print-directory
	$(MAKE) debug -C $(L_CHAMPION_DIR) $(C_NAME) --no-print-directory
	$(MAKE) debug -C $(L_VISUALISER_DIR) $(V_NAME) --no-print-directory

re: fclean all
