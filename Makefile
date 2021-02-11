##
## EPITECH PROJECT, 2020
## makefile
## File description:
## printf
##

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
		src/usage.c 			\
		src/main.c

OBJ		=	$(SRC: .c=.o)

NAME	= 	navy

all: 		$(NAME)

$(NAME):	$(OBJ)
			make -C lib/my
			gcc -g -o $(NAME) $(OBJ) -Llib -lmy -Iinclude

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)
		make fclean -C lib/my

re:		fclean all

.PHONY : all main clean fclean
