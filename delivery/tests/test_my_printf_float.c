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

Test(my_printf, float_precision, .init=redirect_all_std)
{
    my_printf("float with more decimals: %faa\n", 1.23456789);
    cr_assert_stdout_eq_str("float with more decimals: 1.234568aa\n");
}

Test(my_printf, negative_zero_float, .init=redirect_all_std)
{
    my_printf("negative zero: %faaa\n", -0.0);
    cr_assert_stdout_eq_str("negative zero: -0.000000aaa\n");
}

Test(my_printf, infinity_float, .init=redirect_all_std)
{
    my_printf("infinity: %fa\n", INFINITY);
    cr_assert_stdout_eq_str("infinity: infa\n");
}

Test(my_printf, nan_float, .init=redirect_all_std)
{
    my_printf("NaN: %fa\n", NAN);
    cr_assert_stdout_eq_str("NaN: nana\n");
}

Test(my_printf, float_simple, .init=redirect_all_std)
{
    my_printf("float: %fa\n", 3.14);
    cr_assert_stdout_eq_str("float: 3.140000a\n");
}

Test(my_printf, float_negative, .init=redirect_all_std)
{
    my_printf("negative float: %fa\n", -2.71828);
    cr_assert_stdout_eq_str("negative float: -2.718280a\n");
}

Test(my_printf, float_zero, .init=redirect_all_std)
{
    my_printf("zero float: %fa\n", 0.0);
    cr_assert_stdout_eq_str("zero float: 0.000000a\n");
}

Test(my_printf, float_precision_upper, .init=redirect_all_std)
{
    my_printf("float with more decimals: %Faa\n", 1.23456789);
    cr_assert_stdout_eq_str("float with more decimals: 1.234568aa\n");
}

Test(my_printf, negative_zero_float_upper, .init=redirect_all_std)
{
    my_printf("negative zero: %Faaa\n", -0.0);
    cr_assert_stdout_eq_str("negative zero: -0.000000aaa\n");
}

Test(my_printf, infinity_float_upper, .init=redirect_all_std)
{
    my_printf("infinity: %Fa\n", INFINITY);
    cr_assert_stdout_eq_str("infinity: INFa\n");
}

Test(my_printf, nan_float_upper, .init=redirect_all_std)
{
    my_printf("NaN: %Fa\n", NAN);
    cr_assert_stdout_eq_str("NaN: NANa\n");
}

Test(my_printf, float_simple_upper, .init=redirect_all_std)
{
    my_printf("float: %Fa\n", 3.14);
    cr_assert_stdout_eq_str("float: 3.140000a\n");
}

Test(my_printf, float_negative_upper, .init=redirect_all_std)
{
    my_printf("negative float: %Fa\n", -2.71828);
    cr_assert_stdout_eq_str("negative float: -2.718280a\n");
}

Test(my_printf, float_zero_upper, .init=redirect_all_std)
{
    my_printf("zero float: %Fa\n", 0.0);
    cr_assert_stdout_eq_str("zero float: 0.000000a\n");
}