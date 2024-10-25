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

Test(my_printf, normal_hex, .init=redirect_all_std)
{
    my_printf("number: %x zw", 42);
    cr_assert_stdout_eq_str("number: 2a zw");
}

Test(my_printf, multiple_hex, .init=redirect_all_std)
{
    my_printf("number: %x%x zw", 42, 42);
    cr_assert_stdout_eq_str("number: 2a2a zw");
}

Test(my_printf, neg_hex, .init=redirect_all_std)
{
    my_printf("number: %x zw", -8);
    cr_assert_stdout_eq_str("number: fffffff8 zw");
}

Test(my_printf, multiple_neg_hex, .init=redirect_all_std)
{
    my_printf("number: %x %x zw", -8, -12);
    cr_assert_stdout_eq_str("number: fffffff8 fffffff4 zw");
}

Test(my_printf, multiple_neg_hex_nospace, .init=redirect_all_std)
{
    my_printf("number: %x%x zw", -8, -12);
    cr_assert_stdout_eq_str("number: fffffff8fffffff4 zw");
}