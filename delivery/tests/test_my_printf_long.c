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

Test(my_printf, long_max_case, .init=redirect_all_std)
{
    my_printf("long: %lda", LONG_MAX);
    cr_assert_stdout_eq_str("long: 9223372036854775807a");
}

Test(my_printf, long_min_case,  .init=redirect_all_std)
{
    my_printf("long: %lda", -LONG_MAX);
    cr_assert_stdout_eq_str("long: -9223372036854775807a");
}

Test(my_printf, long_number_min, .init=redirect_all_std)
{
    my_printf("long min: %lda\n", LONG_MIN);
    cr_assert_stdout_eq_str("long min: -9223372036854775808a\n");
}