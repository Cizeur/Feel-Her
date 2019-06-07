############################## COMPILE VAR #####################################

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
#CFLAGS		=	-g
HDIR		=	includes
SRCDIR		=	src
SUB1D		=	libft
HFLAGS		=	-I $(HDIR) -I $(SRCDIR)/$(SUB1D)/$(HDIR)
LIBS		=	$(SRCDIR)/$(SUB1D)/libft.a
NAME		=	cgiron-yforeau.filler

############################## SOURCES #########################################

SRCC			=	ft_parser_alloc_double_array.c\
					ft_parser_free_double_array.c\
					ft_parser_get_arrays.c\
					ft_parser_get_dims.c\
					ft_parser_get_player.c\
					ft_solver_check_score.c\
					ft_solver_heatmap.c\
					ft_solver_tab_skim.c\
					main.c\
					parser.c\
					sub_solver.c\

ODIR			=	obj
OBJ				=	$(patsubst %.c,%.o,$(SRCC))

vpath			%.o	$(ODIR)
vpath			%.h	$(HDIR)
vpath			%.h	$(SRCDIR)/$(SUB1D)/$(HDIR)
vpath			%.c	$(SRCDIR)

############################## BUILD ###########################################

all: $(NAME)

$(NAME): $(SRCDIR)/$(SUB1D)/libft.a $(ODIR) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(patsubst %.o,$(ODIR)/%.o,$(OBJ)) $(LIBS)

$(SRCDIR)/$(SUB1D)/libft.a:
	make -C $(SRCDIR)/$(SUB1D)

ft_parser_alloc_double_array.o: filler.h libft.h
ft_parser_get_arrays.o: filler.h libft.h get_next_line.h
ft_parser_get_dims.o: filler.h libft.h get_next_line.h
ft_parser_get_player.o: filler.h libft.h get_next_line.h
ft_solver_check_score.o: filler.h libft.h
ft_solver_heatmap.o: filler.h libft.h
ft_solver_tab_skim.o: filler.h libft.h
main.o: filler.h libft.h c_colors.h
parser.o: filler.h libft.h get_next_line.h
sub_solver.o: filler.h libft.h
%.o: %.c
	@mkdir -p $(ODIR)
	$(CC) -c $(CFLAGS) $< $(HFLAGS) -o $(ODIR)/$@

$(ODIR):
	mkdir -p $@

############################## CLEANUP #########################################

clean:
	rm -rf $(ODIR)
	make -C $(SRCDIR)/$(SUB1D) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
