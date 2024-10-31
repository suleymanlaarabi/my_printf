/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include "lib/my/include/my_printf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

int main(int ac, char **av)
{
    my_printf("%.*f\n", 2, -0.000199);
    printf("%.*f\n", 2,   -0.000199);
    return 0;
}
