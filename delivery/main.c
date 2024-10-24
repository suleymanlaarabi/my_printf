/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <limits.h>
#include <stdarg.h>
#include "lib/my/include/my_printf.h"
#include <stdio.h>

int main(int ac, char **av)
{
    my_printf("char: %c, str: %s, int: %d, uint: %u, hex: %x, oct: %o, float: %f, percent: %%\n",
              'A', "hello", -42, 42, 255, 255, 3.14);
    printf("char: %c, str: %s, int: %d, uint: %u, hex: %x, oct: %o, float: %f, percent: %%\n",
              'A', "hello", -42, 42, 255, 255, 3.14);

    return 0;
}
