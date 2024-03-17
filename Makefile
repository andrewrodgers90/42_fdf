# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arodgers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 19:01:41 by arodgers          #+#    #+#              #
#    Updated: 2024/02/27 10:48:06 by arodgers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

HDR = fdf.h
NAME = fdf
SRCS = fdf.c gnl.c gnl_utils.c split_utils.c split_utils_extra.c ft_atoi_utils.c map.c map_utils.c map_utils_extra.c draw.c draw_utils.c init.c events.c free_utils.c math_utils.c
BONUS_SRCS = fdf.c gnl.c gnl_utils.c split_utils.c split_utils_extra.c ft_atoi_utils.c map.c map_utils.c map_utils_extra.c draw.c draw_utils.c init.c events.c free_utils.c math_utils.c

MLX_DIR = ./minilibx_macos
MLX = $(MLX_DIR)/libmlx.a
MLX_ARG = -framework OpenGl -framework AppKit

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HDR) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) $(MLX_ARG) -o $(NAME)

$(MLX):
	@make -s -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BONUS_OBJS) $(HDR) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLX) $(MLX_ARG) -o $(NAME)
