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

Test(my_printf, max_int_hex, .init=redirect_all_std)
{
    my_printf("number: %xzw", 2147483647);
    cr_assert_stdout_eq_str("number: 7fffffffzw");
}

Test(my_printf, max_int_hex_plusone, .init=redirect_all_std)
{
    my_printf("number: %xzw", 2147483648);
    cr_assert_stdout_eq_str("number: 80000000zw");
}

Test(my_printf, hexa_number, .init=redirect_all_std)
{
    my_printf("hex: %xaaa\n", 255);
    cr_assert_stdout_eq_str("hex: ffaaa\n");
}

Test(my_printf, long_hexa_number, .init=redirect_all_std)
{
    my_printf("long hex: %lxaaa\n", LONG_MAX);
    cr_assert_stdout_eq_str("long hex: 7fffffffffffffffaaa\n");
}