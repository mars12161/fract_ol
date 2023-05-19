# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 12:44:07 by mschaub           #+#    #+#              #
#    Updated: 2023/03/27 17:12:38 by mschaub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants

NAME	:= fract_ol
CFLAGS	:= -Wextra -Wall -Werror -Ofast
LIBMLX	:= ./mlx

# Sources and Headers

HEADERS	:= -I ./include -I $(LIBMLX)/mlx.h
LIBS	:= ./mlx/libmlx_Linux.a -Lmlx_Linux -lX11 -lXext ./ft_printf/libftprintf.a -lm
SRCS	:=	./src/color.c \
			./src/fract_ol.c \
			./src/ft_draw.c \
			./src/ft_complex.c \
			./src/ft_fractol.c \
			./src/ft_printexample.c \
			./src/ft_utils.c \
			./src/hooks.c \

		
OBJS	:= ${SRCS:.c=.o}

# Colors

GREEN = \e[92;5;118m
YELLOW = \e[1;93m

# Rules

all: libmlx $(NAME)

libmlx:
	@cd mlx && bash configure
	@cd ft_printf && make

%.o: %.c $(SRCS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	@echo "$(GREEN)Compiling completed"

clean:
	@rm -f $(OBJS)
	@cd ft_printf && make clean
	@echo "$(YELLOW)Deleting .o files"

fclean: clean
	@rm -f $(NAME)
	@cd ft_printf && make fclean
	@echo "$(YELLOW)Deleting fract_ol executable"

re: clean all

.PHONY: all, clean, fclean, re, libmlx
