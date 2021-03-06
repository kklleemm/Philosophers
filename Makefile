# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdeniau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/01 13:35:39 by cdeniau           #+#    #+#              #
#    Updated: 2016/06/04 19:07:29 by cdeniau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

ALL_CFLAGS	= -Wall -Wextra -Werror -Wno-deprecated
CC			= gcc
RM			= rm -rf

LIBFT_DIR	= ./libft
INC			=	-I./incs -I./libft/includes -I./glfw/include
LINK		=	-L./libft -lft -L./glfw/src/ -lglfw3 -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework GLUT -framework Carbon
OBJS_DIR	= objs
SRCS_DIR	= srcs
INCS_DIR	= incs

SRCS		= main.c			\
			  display.c			\
			  init.c			\
			  form.c			\
			  wait.c			\
			  gameover.c		\
			  stick_r_free.c	\
			  stick_l_free.c	\
			  create_thread.c 	\
			  treatment.c 		\
			  disp_string.c 	\
			  disp_hp.c 		\
			  get_philo_data.c	\
			  disp_free_sticks.c\
			  disp_philo.c		\
			  table_allocation.c
			  
OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) -o $(NAME) $(OBJS) $(LINK)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(ALL_CFLAGS) $(INC) -c $< -o $@
	@echo "\033[A\033[K\033[A"

clean:
	make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

$(OBJS): | $(OBJS_DIR)

$(OBJS_DIR):
	mkdir $(OBJS_DIR)
