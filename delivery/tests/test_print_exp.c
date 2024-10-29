/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** printer
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../lib/my/include/my_printf.h"
#include <limits.h>
#include <float.h>

void redirect_all_std(void);

Test(my_printf, exp_zero, .init=redirect_all_std)
{
    my_printf("exp: %e\n", 0.0);
    cr_assert_stdout_eq_str("exp: 0.000000e+00\n");
}
