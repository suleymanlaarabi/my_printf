/*
** EPITECH PROJECT, 2024
** Nom du projet
** File description:
** Description du projet
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../lib/my/include/my_printf.h"
#include <limits.h>

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, with_d_flag, .init=redirect_all_std)
{
    my_printf("number: %da\n", 42);
    cr_assert_stdout_eq_str("number: 42a\n");
}

Test(my_printf, with_i_flag, .init=redirect_all_std)
{
    my_printf("integer: %iaa\n", -21);
    cr_expect_stdout_eq_str("integer: -21aa\n");
}

Test(my_printf, with_c_flag, .init=redirect_all_std)
{
    my_printf("char: %ca\n", 'A');
    cr_assert_stdout_eq_str("char: Aa\n");
}

Test(my_printf, with_percent_sign, .init=redirect_all_std)
{
    my_printf("percent: %%a\n");
    cr_assert_stdout_eq_str("percent: %a\n");
}

Test(my_printf, mixed_flags, .init=redirect_all_std)
{
    my_printf("char: %c, string: %s, number: %da\n", 'B', "test", 100);
    cr_assert_stdout_eq_str("char: B, string: test, number: 100a\n");
}

Test(my_printf, hard_case_test, .init=redirect_all_std)
{
    my_printf("po%c%s%d%d %% %s baba\n", 'c', "test", 43, 42, "popo");
    cr_expect_stdout_eq_str("poctest4342 % popo baba\n");
}

Test(my_printf, hard_long_max_test, .init=redirect_all_std)
{
    my_printf("po%lda\n", LONG_MAX);
    cr_assert_stdout_eq_str("po9223372036854775807a\n");
}
