##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## navy
##

SRC =		src/error.c				\
			src/error_2.c			\
			src/game_loop.c			\
			src/game_rules.c		\
			src/game_tab_setup.c	\
			src/handle_pos_send.c	\
			src/navy.c				\
			src/signal_converter.c	\
			src/signal.c			\
			src/utilities.c			\
			src/usage.c				\
			src/line_error.c		\
			src/main.c

NAME    =   navy

CFLAGS  =   -Werror -Wall -Wextra -Wshadow -I./include

OBJ     =   $(SRC:.c=.o)

CC      =   gcc

RM      =   rm -rf

all:        $(NAME)

$(NAME):    $(OBJ)
			make -C lib/my/
			$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy

clean:
			make clean -C lib/my
			$(RM) $(OBJ)

fclean:     clean
			make fclean -C lib/my
			$(RM) $(NAME)

re:         fclean all

.PHONY : all clean fclean