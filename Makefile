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

SRC =	src/error.c 			\
		src/error_2.c 			\
		src/game_loop.c 		\
		src/game_rules.c 		\
		src/game_tab_setup.c	\
		src/handle_pos_send.c 	\
		src/navy.c 				\
		src/signal_converter.c 	\
		src/signal.c 			\
		src/utilities.c 		\
		src/main.c

FLAGS = -Werror

re: fclean all

clean:
	$(RM) *.o

fclean:	clean
	$(RM) libmy.a
	$(RM) lib/my/libmy.a

.PHONY : all main clean fclean
