# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschaub <mschaub@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 17:35:04 by mschaub           #+#    #+#              #
#    Updated: 2023/03/13 14:23:33 by mschaub          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

CC = cc

NAME = 		libft.a

HEADER = 	libft.h

RM =		rm -f

SRC =		ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_striteri.c \
			ft_strmapi.c

BONUS =		ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

OBJS = 		$(SRC:.c=.o)

OBJSBONUS =	$(BONUS:.c=.o)

all: 		$(NAME)

%.o: %.c $(SRC)
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): 	$(OBJS)
	@ar -rcs $(NAME) $^
	@echo "Created Libft"

bonus:		$(OBJS) $(OBJSBONUS)
	@ar -rcs	$(NAME) $^

clean:
	@$(RM) $(OBJS) $(OBJSBONUS)
	@echo "Deleted Libft .o files"

fclean: clean
	@$(RM) $(NAME)
	@echo "Libft deleted"

re: fclean all


.PHONY:		all clean fclean re bonus
