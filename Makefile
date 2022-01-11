# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amateo-r <amateo-r@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 10:22:36 by amateo-r          #+#    #+#              #
#    Updated: 2022/01/10 10:22:39 by amateo-r         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	https://projects.intra.42.fr/projects/pipex
#	https://stackoverflow.com/questions/7292642/grabbing-output-from-exec
#	https://stackoverflow.com/questions/13801175/classic-c-using-pipes-in-execvp-function-stdin-and-stdout-redirection

#	SOURCES
SRC		=	./src/main.c
OBJ		=	$(SRC:.c=.o)

#	COMPILER
NAME	=	pipex.a
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

all:		$(NAME)

.%o.%c:		$(CC) $(CFLAGS) $<	-o $@

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

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
