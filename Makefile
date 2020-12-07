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

SRC =	main.c

FLAGS = -Werror -Wextra -Wall -Wshadow

re: fclean all

clean:
	$(RM) *.o

fclean:	clean
	$(RM) libmy.a
	$(RM) lib/my/libmy.a

.PHONY : all main clean fclean
