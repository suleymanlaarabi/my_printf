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
#include <math.h>

int main(int ac, char **av)
{
    my_printf("negative zero: %faaa\n", -0.0);
    printf("negative zero: %faaa\n", -0.0);
    return 0;
}
