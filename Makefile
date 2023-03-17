# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmouhoub <rmouhoub@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 18:05:45 by rmouhoub          #+#    #+#              #
#    Updated: 2023/03/17 18:43:36 by rmouhoub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

LIBFT			=	libft.a

DIR_SRCS		=	srcs/mandatory
DIR_OBJS		=	objs

DIR_TEST		=	test
DIR_PARSING		=	parsing
DIR_MAPPING		=	mapping


SRCS_NAMES 		= 	$(DIR_TEST)/test.c \
					$(DIR_PARSING)/parsing.c \
					$(DIR_PARSING)/utils.c \
					$(DIR_MAPPING)/mult.c \
					

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}

SRCS			=	$(addprefix $(DIR_SRCS)/,$(SRCS_NAMES))
OBJS			=	$(addprefix $(DIR_OBJS)/,$(OBJS_NAMES))

CFLAGS			= -Wall -Werror -Wextra -g3

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

CC				=	cc

HEAD			= -Iincludes -Ilibft 

all				:	${NAME}

$(NAME): $(OBJS)
	make -C libft
	mv libft/libft.a .
	$(CC) $(OBJS) $(CFLAGS) mlx/libmlx.a mlx/libmlx_Linux.a -L. -lXext -L. -lX11 ${LIBFT}  -o $(NAME)
	@echo "\033[34;5mfdf\033[0m"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c | $(DIR_OBJS)
	$(CC)  -c $< -o $@ $(HEAD)

$(DIR_OBJS):
	mkdir -p $(DIR_OBJS)
	mkdir -p objs/test
	mkdir -p objs/parsing
	mkdir -p objs/mapping



clean			:
					make clean -C libft
					rm -rf ${OBJS} 

fclean			:	clean
					make fclean -C libft
					rm -rf ${LIBFT}
					rm -rf ${NAME}

re				:	fclean all

.PHONY			:	all clean fclean re bonus
