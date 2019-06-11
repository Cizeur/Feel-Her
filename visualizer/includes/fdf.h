/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:23:56 by cgiron            #+#    #+#             */
/*   Updated: 2019/06/10 13:24:41 by cgiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# 	include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <errno.h>

# define ESCAPE 53
# define SPACEBAR 49
# define TOUCH_1 18
# define TOUCH_2 19
# define TILDE 50
# define XRES 1080
# define YRES 720
# define FILL_PERCENT 80
# define MAX_XRES 5120
# define MAX_YRES 2880
# define TOP_ROW_THICKNESS 50
# define MLX_PTR 0
# define WIN_PTR 1
# define I_PTR 2
# define I_ADR 3
# define VERT 0
# define HORI 1
# define LAUNCH_S "launched "
# define EXEC_1_S "$$$ exec p1"
# define EXEC_2_S "$$$ exec p2"
# define PLATEAU "Plateau"
# define LN_PLAT_MAP 1
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
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define SCROLL_DOWN 4
# define SCROLL_UP 5
# define ZOOM 1.2
# define TRANSLATE_STEP 100
# define CHESS_COL 16711935
# define COLOR_AMP 1275
# define PUT_IMAGE_ITER 100
# define MIN_MULT 10

typedef struct	s_mouse
{
	int			btn_pressed;
	int			xy[2];
	int			prevxy[2];
}				t_mouse;

typedef struct	s_master
{
	t_list		*output;
	t_list		*current;
	int			fail_ind;
	char		*player_1;
	char		*player_2;
	void		*mem_ptr[4];
	int			turn;
	int			read_lines;
	int			xres;
	int			yres;
	int			map[YRES][XRES][2];
	int			amp_x[3];
	int			amp_o[3];
	float		middle[2];
	int			mult_x;
	int			mult_y;
	int			size[2];
	int			top_corner[2];
	int			updated;
	int			square_tg;
	int			color_1_tg;
	int			color_2_tg;
	t_mouse		mouse;
}				t_master;

void			ft_list_generate(t_master *mstr);
void			ft_exit(int code, t_master *mstr);
void			ft_grid_trace(t_master *mstr, int *size);
void			ft_line_trace(t_master *mstr, int pos[3], int len, int orientation);
void			ft_grid_size(t_master *mstr, int *size);
void			ft_text_draw(t_master *mstr, int pos[2], int color, char *text);
void			ft_refresh(t_master *mstr);
void			ft_grid_fill(t_master *mstr, int *size);
void			sub_parser_stockage(t_master *mstr);
void			ft_init_mstr(t_master *mstr);
void			ft_init_resolution(t_master *mstr, char **argv, int argc);
int				ft_rgb(unsigned char r, unsigned char g, unsigned char b);
int				ft_segment_pixel_len(float *pos1, float *pos2);
void			ft_draw_pixel(t_master *mstr, int x, int y, int color);
void			ft_image_dump(void **mem_ptr);
void			ft_image_fresh(void **mem_ptr, t_master *mstr);
void			ft_init_window(void **mem_ptr, t_master *mstr);
void			ft_plot_grid(t_master *mstr, int *size);
void			ft_caval_proj(t_master *mstr);
void			ft_iso_proj(t_master *mstr);
void			ft_mesh_resize(t_master *mstr, int *size);
void			ft_amp_moy_zval(t_master *mstr);
int				ft_color_pos(int ind, t_master *mstr);
void			ft_mesh_centering(t_master *mstr);
void			ft_mesh_rotation(t_master *mstr);
int				ft_mouse_pressed(int button, int x, int y, t_master *mstr);
int				ft_mouse_released(int button, int x, int y, t_master *mstr);
int				ft_mouse_moved(int x, int y, t_master *mstr);
int				ft_key_simple_press(int key, t_master *mstr);
int				ft_key_loop(int key, t_master *mstr);
void			ft_image_background(t_master *mstr);
void			ft_angle_scale(float angle[3]);
void			ft_init_mult(t_master *mstr, int *size);
void			ft_draw_fill_cell(float poly[2][4], t_master *mstr, int color);
void			ft_cell_init(float cell_ptr[2][4], int ind, t_master *mstr);
int				ft_check_cell(float cell[2][4]);
void			ft_plot_depth_grid (t_master *mstr, int *size);
int				ft_color_gradient(int val, int amp, int color_tg,
		int gradient_tg);
int				ft_checkered_ind(int ind, int size_0);
void			ft_draw_index(t_master *mstr);
void			ft_write_info(t_master *mstr);
void			ft_write_progress(int iter, int present_cells, t_master *mstr);
void			ft_write_usage(void);
void			ft_draw_corners(int ind, t_master *mstr);
void			ft_draw_cell_edge(t_master *mstr, int *size, int ind);
int				ft_check_threshold(t_master *mstr, int ind);
int				ft_color_reading(char *point_val);
int				ft_color_given(int col1, int col2, int amp, int pos);
void			ft_draw_segment_read(t_master *mstr, int ind1, int ind2);
void			ft_draw_segment(t_master *mstr, int ind1, int ind2);
void			ft_check_absent(t_master *mstr);
int				ft_check_cell_inframe(t_master *mstr, int ind, int *size);
void			ft_clear_list(t_list **lst);
void			ft_clear_str_tab(char ***tab);
void			ft_clear_mesh(t_master *mstr, int size);
void			ft_clear_proj(t_master *mstr, int size);

#endif
