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

Test(my_printf, multiple_percent_signs, .init=redirect_all_std)
{
    my_printf("percent signs: %% %% %%aaa\n");
    cr_assert_stdout_eq_str("percent signs: % % %aaa\n");
}

Test(my_printf, no_format_specifiers, .init=redirect_all_std)
{
    my_printf("plain text with no format specifiers");
    cr_assert_stdout_eq_str("plain text with no format specifiers");
}

Test(my_printf, mix_all_flags, .init=redirect_all_std)
{
    my_printf("char: %c, str: %s, int: %d, uint: %u, hex: %x, oct: %o, float: %f, percent: %%  aaaa\n",
              'A', "hello", -42, 42, 255, 255, 3.14);
    cr_expect_stdout_eq_str("char: A, str: hello, int: -42, uint: 42, hex: ff, oct: 377, float: 3.140000, percent: %  aaaa\n");
}
