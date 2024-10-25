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

Test(my_printf, octal_number, .init=redirect_all_std)
{
    my_printf("octal: %oa\n", 255);
    cr_assert_stdout_eq_str("octal: 377a\n");
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

Test(my_printf, null_string, .init=redirect_all_std)
{
    my_printf("string: %saaa\n", NULL);
    cr_assert_stdout_eq_str("string: (null)aaa\n");
}

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

Test(my_printf, extra_arguments, .init=redirect_all_std)
{
    my_printf("number: %daaa\n", 42, 100);
    cr_assert_stdout_eq_str("number: 42aaa\n");
}

Test(my_printf, mix_all_flags, .init=redirect_all_std)
{
    my_printf("char: %c, str: %s, int: %d, uint: %u, hex: %x, oct: %o, float: %f, percent: %%  aaaa\n",
              'A', "hello", -42, 42, 255, 255, 3.14);
    cr_expect_stdout_eq_str("char: A, str: hello, int: -42, uint: 42, hex: ff, oct: 377, float: 3.140000, percent: %  aaaa\n");
}

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

Test(my_printf, long_number_min, .init=redirect_all_std)
{
    my_printf("long min: %lda\n", LONG_MIN);
    cr_assert_stdout_eq_str("long min: -9223372036854775808a\n");
}

Test(my_printf, special_characters_string, .init=redirect_all_std)
{
    my_printf("special chars: %sa\n", "Line1\nLine2\tTabbed");
    cr_assert_stdout_eq_str("special chars: Line1\nLine2\tTabbeda\n");
}

Test(my_printf, zero_padded_number, .init=redirect_all_std)
{
    my_printf("number with leading zeros: %05daaa\n", 42);
    cr_assert_stdout_eq_str("number with leading zeros: 00042aaa\n");
}

Test(my_printf, left_justified_string, .init=redirect_all_std)
{
    my_printf("left justified: %-10sa\n", "test");
    cr_assert_stdout_eq_str("left justified: test      a\n");
}
