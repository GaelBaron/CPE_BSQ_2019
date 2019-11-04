##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## return
##

SRCS    =       src/bsq.c			\
		src/algo.c			\
		src/my_str_to_word_tab.c	\
		src/mapping.c

SRCS2 	=	src/main.c

##TEST 	=

OBJ     =       $(SRCS:.c=.o)

OBJ2    =       $(SRCS2:.c=.o)

BUG	=	-Wall -Wextra -Werror -g3

NAME    =       bsq

$(NAME):        $(OBJ) $(OBJ2)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(OBJ2) -L./lib -lmy

all:    $(NAME)

debug:          $(OBJ) $(OBJ2)
	make DEBUG=yes -C lib/my/
	gcc -o $(NAME) $(OBJ) $(OBJ2) -L./lib -lmy $(BUG)

tests_run:          $(OBJ)
	make -C lib/my/
	gcc -o unit_tests $(TEST) $(OBJ) -L./lib -lmy -Wall -Wextra -Werror -lcriterion --coverage
	./unit_tests

clean:
	make clean -C lib/my/
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean: clean
	make fclean -C lib/my/
	rm -f $(NAME)
	rm -f libmy.a
	rm -f unit_tests

re:     clean all

.PHONY: all clean fclean re test_run
