/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my.h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#ifndef MY_H_
#define MY_H_

/* base */

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strlen_0(char const * str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
void my_sort_int_array(int *tab, int size);
int my_str_isnum(char const *str);
int my_compute_power_rec(int nb, int power);
int my_str_islower(char const *str);
int my_compute_square_root(int nb);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_str_isprintable(char const *str);
int my_find_prime_sup(int nb);
int my_show_word_array(char * const *tab);
int my_showstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_showmem(char const *str, int size);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);

/* Printf*/

int my_printf(const char *format, ...);
int specifier_loop1(const char *format, int *i, va_list ap);
int flags_loop(const char *format, int *i, va_list ap);
int flags_diese(const char *format, int *i);
int flags_space(va_list ap);
void specifier_d(va_list ap);
void specifier_s_min(va_list ap);
void specifier_c(va_list ap);
int specifier_s_maj(va_list ap);
void specifier_u(va_list ap);
void specifier_b(va_list ap);
int my_put_unsigned_nbr(unsigned int nb);
int decimal_to_binary(unsigned int nb);
int decimal_to_octal(int nb);
void specifier_o(va_list ap);
void specifier_x_min(va_list ap);
void specifier_x_maj(va_list ap);
int decimal_to_hexa_min(int nb);
int decimal_to_hexa_maj(int nb);
void specifier_p(va_list ap);
void specifier_pourcent(va_list ap);


/* FUNCTION */

int encryption(char **av);
int decryption(void);
int display_matrix(char **av, int *dimension, int *result);
int check_error(int ac, char **av);
int display_encryption_message(char **av);
int calcul_encryption(char **av, int *dimension, int i);

#endif
