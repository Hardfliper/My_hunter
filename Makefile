##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

SRC	=	src/hunter.c	\
		src/secondary_functions.c	\
		src/main.c
NOMAIN	=	src/hunter.c	\
		src/secondary_functions.c

NAME	=	my_hunter

CRITNAME =	unit_test

TEST	=	./tests/test.c

LIB	=	-L ./lib/my/ -lmy

CSFML	=	-lcsfml-graphics -lcsfml-window -lcsfml-system

OBJ     =	*.gcno  \
		*.gcda

all	:	$(NAME)

$(NAME)	:
		make -C ./lib/my/
		gcc $(LIB) -o $(NAME) $(SRC) $(CSFML) $(LIB)

test_run:
	make re
	gcc -o $(CRITNAME) $(NOMAIN) $(TEST) $(LIB) --coverage -lcriterion $(CSFML)
	./unit_test
	gcovr --exclude tests/

clean	:
		rm -f $(OBJ)
		make clean -C ./lib/my/

fclean	:	clean
		rm -f $(NAME) $(CRITNAME)
		make fclean -C ./lib/my/

re	:	fclean all

.PHONY	:	all clean fclean re
