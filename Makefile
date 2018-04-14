# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikozlov <ikozlov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/08 21:31:12 by ikozlov           #+#    #+#              #
#    Updated: 2018/04/14 00:22:26 by ikozlov          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# compiler
CC = gcc
DEBUG = -g
FLAGS = -Wall -Wextra -Werror
FLAGS += $(DEBUG)

# directories
OBJ_DIR = obj/
SRC_DIR = src/
INC_DIR = includes/
LIBFT_DIR = libft/
MLX_DIR = minilibx/

# files
SRC_FILES = $(notdir $(wildcard $(SRC_DIR)*.c))
OBJ_FILES = $(SRC_FILES:%.c=%.o)

# full paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# libraries
LIBFT = $(LIBFT_DIR)libft.a
LIBMLX = $(MLX_DIR)libmlx.a
LIB = $(LIBFT)
LIB += $(LIBMLX)
LIB += -framework OpenGL -framework AppKit

# includes
INCLUDES = -I $(LIBFT_DIR)includes -I includes/ -I $(MLX_DIR)

# norm
NORM = norminette
NORM_OUR = norm.out
NORM_ERR = norm.err

all: $(NAME)

norm:
	@$(NORM) $(SRC_DIR) $(INC_DIR) > $(NORM_OUR)
	@cat $(NORM_OUR) | grep "Error" > $(NORM_ERR) || touch $(NORM_ERR)
	@if test -s $(NORM_ERR); then\
		cat $(NORM_OUR);\
	else\
		echo "You all set!";\
	fi;
	@rm -rf $(NORM_OUR) $(NORM_ERR)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@$(MAKE) -C $(MLX_DIR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
	@echo "[INFO] $(NAME) executable created"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean
	@if [ -d "./$(OBJ_DIR)" ]; then\
		/bin/rm -rf $(OBJ_DIR);\
		/bin/echo "[INFO] Objects removed.";\
	fi;

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@if test -e $(NAME); then\
		/bin/rm $(NAME);\
		/bin/echo "[INFO] $(NAME) executable deleted";\
	fi;

re: fclean all

.PHONY: all $(NAME) clean fclean re norm