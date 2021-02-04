##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile
##

SRC	=	my_putchar.c			\
		my_put_nbr.c			\
		my_putstr.c			\
		my_revstr.c			\
		my_compute_power_rec.c		\
		my_find_prime_sup.c		\
		my_getnbr.c			\
		my_isneg.c			\
		my_is_prime.c			\
		my_showmem.c			\
		my_showstr.c			\
		my_show_word_array.c		\
		my_sort_int_array.c		\
		my_strcapitalize.c		\
		my_strcat.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_str_isalpha.c		\
		my_str_islower.c		\
		my_str_isnum.c			\
		my_str_isprintable.c		\
		my_str_isupper.c		\
		my_strlen_0.c			\
		my_strlen.c			\
		my_strlowcase.c			\
		my_strncat.c			\
		my_strcmp.c			\
		my_strncpy.c			\
		my_strstr.c			\
		my_strupcase.c			\
		my_swap.c			\
		my_put_unsigned_nbr.c		\
		my_conversion_from_decimal.c	\
		my_printf/specifier1.c		\
		my_printf/specifier2.c		\
		my_printf/specifier3.c		\
		my_printf/flags.c		\
		my_printf/my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-I../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar -rc $(NAME) $(OBJ)
	cp libmy.a  ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
