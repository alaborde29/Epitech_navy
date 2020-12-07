/*
** EPITECH PROJECT, 2020
** B-PSU-101-NAN-1-1-navy-enzo.bonato
** File description:
** navy
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#ifndef NAVY_H_
#define NAVY_H_

int error(int ac, char **av);
char *read_file(char *path, char *buffer);
int is_size_normal(char *str);

#endif /* !NAVY_H_ */
