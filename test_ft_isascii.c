/* test_ft_isascii.c */
#include "libft.h"

int main(void)
{
    int  tests[]    = { 0, 1, 127, 128, -1, 200 };
    int  expected[] = { 1, 1,   1,   0,   0,   0 };
    size_t n_tests   = sizeof(tests) / sizeof(tests[0]);
    int    ok        = 1;
    size_t failed_i  = 0;

    for (size_t i = 0; i < n_tests; ++i)
    {
        if (ft_isascii(tests[i]) != expected[i])
        {
            ok       = 0;
            failed_i = i;
            break;
        }
    }

    ft_putstr_fd("Test result: ", 1);
    ft_putchar_fd(ok ? '1' : '0', 1);
    if (ok)
        ft_putstr_fd(" (All edge cases true)\n", 1);
    else
    {
        ft_putstr_fd(" (Edge case #", 1);
        ft_putnbr_fd(failed_i, 1);
        ft_putstr_fd(" wrong)\n", 1);
    }
    return (ok);
}
