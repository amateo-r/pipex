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