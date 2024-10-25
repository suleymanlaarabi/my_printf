/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** printer
*/

#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include <criterion/redirect.h>
#include "../lib/my/include/my_printf.h"
#include <limits.h>
#include <float.h>

void redirect_all_std(void);

Test(my_printf, unsigned_int_max, .init=redirect_all_std)
{
    my_printf("unsigned max: %ua\n", UINT_MAX);
    cr_assert_stdout_eq_str("unsigned max: 4294967295a\n");
}

Test(my_printf, unsigned_zero, .init=redirect_all_std)
{
    my_printf("unsigned zero: %ua\n", 0);
    cr_assert_stdout_eq_str("unsigned zero: 0a\n");
}