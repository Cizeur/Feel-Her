/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_visualiser.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:23:56 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/14 11:24:53 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_VISUALISER_H
# define FILLER_VISUALISER_H

# include <mlx.h>
# include <stdlib.h>
# 	include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <errno.h>

/* ********************************************** */
/*                  DEFINES                       */
/* ********************************************** */
/*
**	TOUCHES
*/
# define ESCAPE 53
# define SPACEBAR 49
# define TOUCH_1 18
# define TOUCH_2 19
# define TOUCH_P 35
# define TOUCH_R 15
# define TOUCH_Q 12
# define TOUCH_W 13
# define TOUCH_L 37
# define TILDE 50
/*
**	UPDATE VALUES
*/
# define U_TO_LOOSE 4
# define U_TO_THE_END 3
# define U_THE_MAP 1
# define U_ONE_TURN 2
# define U_IDLE 0
/*
**	TEXT SIZE
*/
# define LARGEUR_CHAR 10
/*
**	READ BUFFER
*/
# define BUFFER_READ 65536
# define BUFFER_LINE (2 * BUFFER_READ) + 1
/*
**	WINDOW SIZE
*/
# define XRES 1080
# define YRES 720
# define MAX_XRES 5120
# define MAX_YRES 2880
# define FILL_PERCENT 80
# define TOP_ROW_THICKNESS 100
/*
**	ERROR STRINGS
*/
# define END_S "fin"
# define LAUNCH_S "launched "
# define EXEC_1_S "$$$ exec p1"
# define EXEC_2_S "$$$ exec p2"
# define INVERT "$$$ invert"
# define PLATEAU_S "Plateau"
# define ERROR_S "An error occured. aborting..."
/*
**	CLARIFICATIONS
*/
# define MLX_PTR 0
# define WIN_PTR 1
# define I_PTR 2
# define I_ADR 3
# define VERT 0
# define HORI 1
/*
**	EXIT VALUE
*/
# define STANDARD_EXIT -1
# define FAIL_EMPTY_FILE 0
# define FAIL_WINDOW_CREATION 1
# define FAIL_FILE_OPEN 2
# define FAIL_READ_LINE 3
# define FAIL_ADD_LIST 4
# define FAIL_IMAGE_CREATION 5
# define FAIL_LINE_LEN 6
# define FAIL_SPLIT_WHITESPACE 7
# define FAIL_WINDOW_TO_SMALL 8
# define FAIL_LISTING 9
/*
**	RAINBOW AMPLITUDE
*/
# define COLOR_AMP 1275

/* ********************************************** */
/*                  STRUCTURE                     */
/* ********************************************** */

typedef struct	s_master
{
	int			xres;
	int			yres;
	void		*mem_ptr[4];
	t_list		*output;
	t_list		*current;
	char		*buffer_pos;
	int			still_reading;
	int			read_lines;
	char		*player_1;
	char		*player_2;
	int			score_1;
	int			score_2;
	int			map[YRES][XRES][2];
	int			amp_x[3];
	int			amp_o[3];
	int			mult_x;
	int			mult_y;
	int			size[2];
	int			top_corner[2];
	int			updated;
	int			square_tg;
	int			color_1_tg;
	int			color_2_tg;
	int			color_1_g_tg;
	int			color_2_g_tg;
}				t_master;

/* ********************************************** */
/*                  PROTOTYPES                    */
/* ********************************************** */

void			ft_list_generate(t_master *mstr);
void			ft_exit(int code, t_master *mstr);
void			ft_refresh(t_master *mstr);
int				ft_rgb(unsigned char r, unsigned char g, unsigned char b);
/*
**	INITIALISATION
*/
void			ft_init_mstr(t_master *mstr);
void			ft_init_resolution(t_master *mstr, char **argv, int argc);
/*
**	PARSER ENTREE STANDARD
*/
void			sub_parser_stockage(t_master *mstr);
int				ft_parser_check_size(char *line, int *size);
/*
**	BIBLIOTEQUE WINDOW
*/
void			ft_window_init(void **mem_ptr, t_master *mstr);
void			ft_window_text_draw(t_master *mstr, int pos[2], int color, char *text);
void			ft_window_text_top_bar(t_master *mstr);
/*
**	BIBLIOTEQUE IMAGE
*/
void			ft_image_init(void **mem_ptr, t_master *mstr);
void			ft_image_background(t_master *mstr);
void			ft_image_line_trace(t_master *mstr, int pos[3], int len, int orientation);
void			ft_image_draw_pixel(t_master *mstr, int x, int y, int color);
void			ft_image_top_bar_bg(t_master *mstr);
void			ft_image_dump(void **mem_ptr);
/*
**	BIBLIOTEQUE TRACING
*/
void			ft_tracer(t_master *mstr);
void			ft_tracer_grid(t_master *mstr, int *size);
void			ft_tracer_grid_size(t_master *mstr, int *size);
void			ft_tracer_grid_fill(t_master *mstr, int *size);
/*
**	
*/
int				ft_key_simple_press(int key, t_master *mstr);
int				ft_key_loop(int key, t_master *mstr);
int				ft_color_gradient(int val, int amp, int col_tg, int grad_tg);
void			ft_write_usage(void);
void			ft_clear_list(t_list **lst);

#endif
