# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfassad <mfassad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/10 13:31:05 by mfassad           #+#    #+#              #
#    Updated: 2026/10/05 10:39:28 by mfassad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -Iincludes -Ilibft -Iget_next_line

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = \
	src/main.c \
	src/initialization/init_config.c \
	src/parsing/parse_file_utils.c \
	src/parsing/parse_file.c \
	src/parsing/validate_texture.c \
	src/parsing/parse_texture.c \
	src/parsing/parse_color.c \
	src/parsing/parser_utils.c \
	src/parsing/validate_filename.c \
	src/parsing/identify_line.c \
	src/parsing/read_file.c \
	src/parsing/config_validation.c \
	src/parsing/store_map.c \
	src/parsing/validate_map.c \
	get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re