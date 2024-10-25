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
#include <string.h>

void redirect_all_std(void);

Test(my_printf, width_specifier, .init=redirect_all_std)
{
    my_printf("Width 10: %10sa\n", "test");
    cr_assert_stdout_eq_str("Width 10:       testa\n");
}

Test(my_printf, left_justified_width, .init=redirect_all_std)
{
    my_printf("Left-justified width 10: %-10sa\n", "test");
    cr_assert_stdout_eq_str("Left-justified width 10: test      a\n");
}

Test(my_printf, precision_specifier, .init=redirect_all_std)
{
    my_printf("Precision 5: %.5sa\n", "testing");
    cr_assert_stdout_eq_str("Precision 5: testia\n");
}

Test(my_printf, width_and_precision, .init=redirect_all_std)
{
    my_printf("Width 10 and Precision 5: %10.5sa\n", "testing");
    cr_assert_stdout_eq_str("Width 10 and Precision 5:      testia\n");
}

Test(my_printf, left_justified_width_and_precision, .init=redirect_all_std)
{
    my_printf("Left-justified Width 10 and Precision 5: %-10.5sa\n", "testing");
    cr_assert_stdout_eq_str("Left-justified Width 10 and Precision 5: testi     a\n");
}

Test(my_printf, zero_padding_ignored_with_string, .init=redirect_all_std)
{
    my_printf("Zero padding with string: %010sa\n", "test");
    cr_assert_stdout_eq_str("Zero padding with string:       testa\n");
}

Test(my_printf, special_characters_in_string, .init=redirect_all_std)
{
    my_printf("Special chars: %sa\n", "Hello\nWorld\t!");
    cr_assert_stdout_eq_str("Special chars: Hello\nWorld\t!a\n");
}

Test(my_printf, long_string, .init=redirect_all_std)
{
    char long_str[1024];
    char long_str_expect[2048];
    memset(long_str, 'a', 1023);
    long_str[1023] = '\0';
    my_printf("Long string: %sa\n", long_str);
    sprintf(long_str_expect, "Long string: %sa\n", long_str);
    cr_assert_stdout_eq_str(long_str_expect);
}

Test(my_printf, mixing_specifiers, .init=redirect_all_std)
{
    my_printf("String: %s, Int: %d, Char: %ca\n", "test", 42, 'A');
    cr_assert_stdout_eq_str("String: test, Int: 42, Char: Aa\n");
}

Test(my_printf, negative_precision, .init=redirect_all_std)
{
    my_printf("Negative precision %. -5sa\n", "testing");
    cr_assert_stdout_eq_str("Negative precision testinga\n");
}

Test(my_printf, non_printable_characters, .init=redirect_all_std)
{
    char str_with_nonprintable[] = "Hello\x01\x02\x03World";
    my_printf("Non-printable: %sa\n", str_with_nonprintable);
    cr_assert_stdout_eq_str("Non-printable: Hello\x01\x02\x03Worlda\n");
}

Test(my_printf, percent_sign, .init=redirect_all_std)
{
    my_printf("Percent sign: %%sa\n");
    cr_assert_stdout_eq_str("Percent sign: %sa\n");
}

Test(my_printf, string_with_percent_sign, .init=redirect_all_std)
{
    my_printf("String with percent: %sa\n", "100%");
    cr_assert_stdout_eq_str("String with percent: 100%a\n");
}

Test(my_printf, zero_precision, .init=redirect_all_std)
{
    my_printf("Zero precision: %.0sa\n", "test");
    cr_assert_stdout_eq_str("Zero precision: a\n");
}

Test(my_printf, width_zero_precision, .init=redirect_all_std)
{
    my_printf("Width and zero precision: %10.0sa\n", "test");
    cr_assert_stdout_eq_str("Width and zero precision:           a\n");
}

Test(my_printf, precision_larger_than_string, .init=redirect_all_std)
{
    my_printf("Precision larger than string: %.10sa\n", "test");
    cr_assert_stdout_eq_str("Precision larger than string: testa\n");
}

Test(my_printf, width_smaller_than_string, .init=redirect_all_std)
{
    my_printf("Width smaller than string: %2sa\n", "test");
    cr_assert_stdout_eq_str("Width smaller than string: testa\n");
}
