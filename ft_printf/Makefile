# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 14:31:34 by mschaub           #+#    #+#              #
#    Updated: 2023/03/13 14:24:50 by mschaub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

CC = 		cc

CFLAGS = 	-Wall -Wextra -Werror

RM = 		rm -f

LIBFT = ./Libft/libft.a

SRC = 		ft_printf.c \
			ft_print_unsigned.c \
			ft_printchar.c \
			ft_printhex.c \
			ft_printnbr.c \
			ft_printperc.c \
			ft_printstr.c \
			ft_printptr.c

OBJS =		${SRC:.c=.o}

all: $(NAME)

%.o: %.c $(SRC)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): 	$(OBJS)
	@make -C ./Libft
	@cp ./Libft/libft.a $(NAME)
	@$(CC) $(CFLAGS) -c -I Libft/ft_printf.h $(SRC)
	@ar -rcs $(NAME) $^
	@echo "Created libftprintf"

clean:
	@make clean -C ./Libft
	@$(RM) $(OBJS)
	@echo "Removed printf .o files"

fclean: clean
	@make fclean -C ./Libft
	@$(RM) $(NAME)
	@echo "Deleted libftprintf lib"

re: fclean all


.PHONY:		all clean fclean re bonus