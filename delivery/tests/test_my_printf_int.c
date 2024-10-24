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

Test(my_printf, normal_int, .init=redirect_all_std)
{
    my_printf("number: %d zw", 42);
    cr_assert_stdout_eq_str("number: 42 zw");
}

Test(my_printf, extra_args, .init=redirect_all_std)
{
    my_printf("number: %d zw", 42, 100);
    cr_assert_stdout_eq_str("number: 42 zw");
}

Test(my_printf, spec_int_zero, .init=redirect_all_std)
{
    my_printf("is number %05d zzz", 12);
    cr_assert_stdout_eq_str("is number 00012 zzz");
}

Test(my_printf, spec_int_none, .init=redirect_all_std)
{
    my_printf("is number %5d eaz", 12);
    cr_assert_stdout_eq_str("is number    12 eaz");
}

Test(my_printf, spec_int_multiple, .init=redirect_all_std)
{
    my_printf("is number %5d%04d eza", 12, 8);
    cr_assert_stdout_eq_str("is number    120008 eza");
}