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
#include <math.h>

void redirect_all_std(void);

Test(my_printf, normal_octal, .init=redirect_all_std)
{
    my_printf("number: %o zw", 42);
    cr_assert_stdout_eq_str("number: 52 zw");
}

Test(my_printf, multiple_octal, .init=redirect_all_std)
{
    my_printf("number: %o%o zw", 42, 42);
    cr_assert_stdout_eq_str("number: 5252 zw");
}

Test(my_printf, neg_octal, .init=redirect_all_std)
{
    my_printf("number: %o zw", -8);
    cr_assert_stdout_eq_str("number: 37777777770 zw");
}

Test(my_printf, multiple_neg_octal, .init=redirect_all_std)
{
    my_printf("number: %o %o zw", -8, -12);
    cr_assert_stdout_eq_str("number: 37777777770 37777777764 zw");
}

Test(my_printf, multiple_neg_octal_nospace, .init=redirect_all_std)
{
    my_printf("number: %o%o zw", -8, -12);
    cr_assert_stdout_eq_str("number: 3777777777037777777764 zw");
}