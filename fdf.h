/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arodgers <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:34:32 by arodgers          #+#    #+#             */
/*   Updated: 2024/01/21 14:23:53 by arodgers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "minilibx_macos/mlx.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	char			*cont;
	struct s_list	*next;
}	t_list;

typedef struct s_clean
{
	t_list	*new_node;
	t_list	*last;
	char	*new_line;
	int		i;
	int		j;
}	t_clean;

typedef struct s_point
{
	float	x1;
	float	y1;
	float	x_step;
	float	y_step;
	int		z;
	int		z1;
	int		max;
	int		colour;
}	t_point;

typedef struct s_img
{
	void	*imgptr;
	char	*pxls_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_map
{
	int		height;
	int		*width;
	int		size;
	int		**matrix;
	int		max_z;
	int		min_z;
	float	zoom;
	float	zoom_factor;
	float	angle;
	int		x_offset;
	int		y_offset;
	int		fd;
	char	*file;
	char	*line;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_map;

typedef struct s_var
{
	t_map	*map;
	t_img	img;
}	t_var;

// main utils

void	handle_error(int flag);

void	print_instructions(void);

// init utils

t_map	*init_map(char *file, t_map *map);

void	init_mlx(t_var *vars);

// map_utils

void	allocate_map(t_map *map);

void	fill_map(char *line, int *width);

int		get_height(t_map *map);

int		*get_width(t_map *map);

int		get_max_z(t_map *map);

int		get_min_z(t_map *map);

int		count_words(char *str, char c);

float	get_zoom(t_map *map);

float	get_zoom_factor(float zoom);

// draw_utils

void	draw_map(t_var vars);

void	draw_line(float x, float y, t_point point, t_var vars);

void	my_pixel_put(t_var vars, int x, int y, int color);

int		get_colour(t_point *point, t_map *map);

void	make_3d(float *x, float *y, t_point *point, t_map *map);

void	shift(float *x, float *y, t_point *point, t_var vars);

void	zoom(float *x, float *y, t_point *point, t_map *map);

void	set_point(int c, int x, int y, t_point *point);

// maths utils

float	get_max(float x, float y);

float	absolute(float n);

// events utils

int		read_keys(int key_press, t_var *vars);

void	move_image(int key, t_var *vars);

void	zoom_image(int key_press, t_var *vars);

void	rotate_image(int key_press, t_var *vars);

int		close_window(int key_code, t_map *map);

// free utils

void	free_all(t_map *map);

void	free_mlx(t_map *map);

void	free_matrix(int j, t_map *map);

int		ft_open(char *file);

// gnl utils

t_list	*ft_lstlast(t_list *lst);

int		find_newline(t_list *list);

void	copy_chars(t_list *list, char *str);

int		get_len(t_list *list);

char	*fetch_line(t_list *list);

void	free_list(t_list **list, t_list *clean_node, char *new_line);

void	add_to_node(t_list **list, char *buffer);

int		clean_list(t_list **list);

void	create_list(t_list **list, int fd);

char	*get_next_line(int fd);

// ft_atoi utils

int		ft_isdigit(int c);

int		ft_is_sign(int c);

int		ft_overflow_check(int sign);

int		ft_atoi(const char *str);

// ft_split utils

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

size_t	ft_strlen(const char *s);

void	ft_putstr_fd(char *s, int fd);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	**ft_freeall(char **arr, int i);

char	**ft_allocatewords(char **arr, char const *s, char sep);

int		ft_wordcount(char const *s, char sep);

char	**ft_split(char const *s, char c);

#endif
