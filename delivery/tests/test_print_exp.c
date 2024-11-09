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

Test(my_printf, exp_basic, .init=redirect_all_std)
{
    my_printf("%e",1.0);
    cr_assert_stdout_eq_str("1.000000e+00");
}

Test(my_printf, exp_basic_neg, .init=redirect_all_std)
{
    my_printf("%e",-1.0);
    cr_assert_stdout_eq_str("-1.000000e+00");
}

Test(my_printf, exp_more, .init=redirect_all_std)
{
    my_printf("%e",1234.0);
    cr_assert_stdout_eq_str("1.234000e+03");
}

Test(my_printf, exp_more_neg, .init=redirect_all_std)
{
    my_printf("%e",-1234.0);
    cr_assert_stdout_eq_str("-1.234000e+03");
}

Test(my_printf, exp_less, .init=redirect_all_std)
{
    my_printf("%e",0.1234);
    cr_assert_stdout_eq_str("1.234000e-01");
}

Test(my_printf, exp_less_neg, .init=redirect_all_std)
{
    my_printf("%e",-0.1234);
    cr_assert_stdout_eq_str("-1.234000e-01");
}

Test(my_printf, exp_less2, .init=redirect_all_std)
{
    my_printf("%e",0.1034);
    cr_assert_stdout_eq_str("1.034000e-01");
}

Test(my_printf, exp_less_neg2, .init=redirect_all_std)
{
    my_printf("%e",-0.1034);
    cr_assert_stdout_eq_str("-1.034000e-01");
}

Test(my_printf, exp_less3, .init=redirect_all_std)
{
    my_printf("%e",0.001034);
    cr_assert_stdout_eq_str("1.034000e-03");
}

Test(my_printf, exp_less_neg3, .init=redirect_all_std)
{
    my_printf("%e",-0.001034);
    cr_assert_stdout_eq_str("-1.034000e-03");
}
