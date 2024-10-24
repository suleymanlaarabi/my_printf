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

Test(my_printf, unsigned_int_max, .timeout=4, .init=redirect_all_std)
{
    my_printf("unsigned max: %u", UINT_MAX);
    cr_assert_stdout_eq_str("unsigned max: 4294967295");
}

Test(my_printf, unsigned_zero, .timeout=4, .init=redirect_all_std)
{
    my_printf("unsigned zero: %u", 0);
    cr_assert_stdout_eq_str("unsigned zero: 0");
}

Test(my_printf, float_simple, .timeout=4, .init=redirect_all_std)
{
    my_printf("float: %f", 3.14);
    cr_assert_stdout_eq_str("float: 3.140000");
}

Test(my_printf, float_negative, .timeout=4, .init=redirect_all_std)
{
    my_printf("negative float: %f", -2.71828);
    cr_assert_stdout_eq_str("negative float: -2.718280");
}

Test(my_printf, float_zero, .timeout=4, .init=redirect_all_std)
{
    my_printf("zero float: %f", 0.0);
    cr_assert_stdout_eq_str("zero float: 0.000000");
}

Test(my_printf, octal_number, .timeout=4, .init=redirect_all_std)
{
    my_printf("octal: %o", 255);
    cr_assert_stdout_eq_str("octal: 377");
}

Test(my_printf, hexa_number, .timeout=4, .init=redirect_all_std)
{
    my_printf("hex: %x", 255);
    cr_assert_stdout_eq_str("hex: ff");
}

Test(my_printf, long_hexa_number, .timeout=4, .init=redirect_all_std)
{
    my_printf("long hex: %lx", LONG_MAX);
    cr_assert_stdout_eq_str("long hex: 7fffffffffffffff");
}

Test(my_printf, null_string, .timeout=4, .init=redirect_all_std)
{
    my_printf("string: %s", NULL);
    cr_assert_stdout_eq_str("string: (null)");
}

Test(my_printf, multiple_percent_signs, .timeout=4, .init=redirect_all_std)
{
    my_printf("percent signs: %% %% %%");
    cr_assert_stdout_eq_str("percent signs: % % %");
}

Test(my_printf, no_format_specifiers, .timeout=4, .init=redirect_all_std)
{
    my_printf("plain text with no format specifiers");
    cr_assert_stdout_eq_str("plain text with no format specifiers");
}

Test(my_printf, extra_arguments, .timeout=4, .init=redirect_all_std)
{
    my_printf("number: %d", 42, 100);
    cr_assert_stdout_eq_str("number: 42");
}

Test(my_printf, mix_all_flags, .timeout=4, .init=redirect_all_std)
{
    my_printf("char: %c, str: %s, int: %d, uint: %u, hex: %x, oct: %o, float: %f, percent: %%",
              'A', "hello", -42, 42, 255, 255, 3.14);
    cr_assert_stdout_eq_str("char: A, str: hello, int: -42, uint: 42, hex: ff, oct: 377, float: 3.140000, percent: %");
}

Test(my_printf, float_precision, .timeout=4, .init=redirect_all_std)
{
    my_printf("float with more decimals: %f", 1.23456789);
    cr_assert_stdout_eq_str("float with more decimals: 1.234568");
}

Test(my_printf, negative_zero_float, .timeout=4, .init=redirect_all_std)
{
    my_printf("negative zero: %f", -0.0);
    cr_assert_stdout_eq_str("negative zero: -0.000000");
}

Test(my_printf, infinity_float, .timeout=4, .init=redirect_all_std)
{
    my_printf("infinity: %f", INFINITY);
    cr_assert_stdout_eq_str("infinity: inf");
}

Test(my_printf, nan_float, .timeout=4, .init=redirect_all_std)
{
    my_printf("NaN: %f", NAN);
    cr_assert_stdout_eq_str("NaN: nan");
}

Test(my_printf, long_number_min, .timeout=4, .init=redirect_all_std)
{
    my_printf("long min: %ld", LONG_MIN);
    cr_assert_stdout_eq_str("long min: -9223372036854775808");
}

Test(my_printf, special_characters_string, .timeout=4, .init=redirect_all_std)
{
    my_printf("special chars: %s", "Line1\nLine2\tTabbed");
    cr_assert_stdout_eq_str("special chars: Line1\nLine2\tTabbed");
}

Test(my_printf, zero_padded_number, .timeout=4, .init=redirect_all_std)
{
    my_printf("number with leading zeros: %05d", 42);
    cr_assert_stdout_eq_str("number with leading zeros: 00042");
}

Test(my_printf, left_justified_string, .timeout=4, .init=redirect_all_std)
{
    my_printf("left justified: %-10s", "test");
    cr_assert_stdout_eq_str("left justified: test      ");
}
