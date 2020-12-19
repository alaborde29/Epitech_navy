##
## EPITECH PROJECT, 2020
## makefile
## File description:
## printf
##

all:
	make -C lib/my/
	gcc -o $(NAME) $(SRC) $(FLAGS) $(CSFML) -I./include -L./lib/my -lmy

NAME = navy

SRC =	src/error.c 		\
		src/error_2.c 		\
		src/game_tab_setup.c\
		src/navy.c 			\
		src/utilities.c 	\
		src/signal.c		\
		src/main.c

FLAGS = -Werror

re: fclean all

clean:
	$(RM) *.o

fclean:	clean
	$(RM) libmy.a
	$(RM) lib/my/libmy.a

.PHONY : all main clean fclean
