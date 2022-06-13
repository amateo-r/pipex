# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 10:22:36 by amateo-r          #+#    #+#              #
#    Updated: 2022/06/12 10:55:56 by amateo-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	SOURCES
SRC			=	./src/main.c \
				./src/ft_strlcpy.c \
				./src/ft_strlcat.c \
				./src/ft_strncmp.c \
				./src/ft_split.c \
				./src/ft_substr.c \
				./src/ft_strlen.c \
				./src/ft_calloc.c \
				./src/ft_bzero.c \
				./src/ft_memset.c \
				./src/ft_strdup.c \
				./src/ft_strcpy.c \
				./src/exception_manager.c
OBJ			=	$(SRC:.c=.o)

#	COMPILER
NAME		=	pipex
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -f

all:		$(NAME)

.%o.%c:		$(CC) $(CFLAGS) $<	-o $@

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o	$(NAME)

norme:
			@echo "---- SRC ----"
			@norminette ./src
			@echo "---- INCLUDE ----"
			@norminette ./include

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
