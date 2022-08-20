##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## desc
##
## -I../includes

NAME	=		runner

CFLAGS	= 		-W -Wall -Wextra

SRC		=		./src/main.c			\

CSFML	=		-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

OBJ		=		$(SRC:.c=.o)

all:	$(OBJ)
		gcc $(SRC) -o $(NAME) $(CSFML)

apple:	$(OBJ)
		/usr/bin/arch -x86_64 gcc $(SRC) -o $(NAME) $(CSFML)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
		make fclean -C ./lib/my/

re:	fclean all