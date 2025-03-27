# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kharuya <haruya.0411.k@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/27 15:23:46 by kharuya           #+#    #+#              #
#    Updated: 2025/03/27 19:28:46 by kharuya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -g -fsanitize=leak


INCS			=	-I includes/ -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(MLX_DIR)

SRCS_PATH		=	src/
SRCS_PARSE_PATH =	src/parse_processing/
SRCS			=	$(wildcard $(SRCS_PATH)*.c ) $(wildcard $(SRCS_PARSE_PATH)*.c)

OBJS_PATH		=	objs/
OBJS			=	$(SRCS:src/%.c=objs/%.o)

LIBFT_DIR		=	libft/
LIBFT			=	$(LIBFT_DIR)libft.a

PRINTF_DIR		=	ft_printf/
PRINTF			=	$(PRINTF_DIR)libftprintf.a

MLX_DIR			=	minilibx/
MLX				=	$(MLX_DIR)libmlx_Linux.a
FRAMEWORKS		=	-lXext -lX11 -lm -lbsd

MLX_MAC			=	$(MLX_DIR)libmlx_Darwin.a
FRAMEWORKS_MAC	=	-L /usr/X11/include/../lib -lXext -lX11

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	INCS += -I /usr/X11/include
    MLX = $(MLX_MAC)
    FRAMEWORKS = $(FRAMEWORKS_MAC)
endif

all:	$(NAME)

$(NAME): $(MLX) $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) $(LIBFT) $(PRINTF) $(MLX) $(FRAMEWORKS) -o $(NAME)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@


bonus:	all


$(LIBFT):
	make bonus -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX): | $(MLX_DIR)
	$(MAKE) -C $(MLX_DIR)

$(MLX_DIR):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR)


clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)
	rm -rf $(OBJS_PATH)

fclean:
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -rf $(MLX_DIR)
	rm -rf $(OBJS_PATH)
	rm -f $(NAME)

re:		fclean all

.PHONY:	all bonus clean fclean re
