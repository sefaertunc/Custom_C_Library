/* test_ft_itoa.c */
#include "libft.h"

int main(void)
{
    int   tests[]    = {
        0,
        42,
        -42,
        2147483647,
        -2147483648
    };
    const char *expected[] = {
        "0",
        "42",
        "-42",
        "2147483647",
        "-2147483648"
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;

    for (size_t i = 0; i < n_tests; ++i)
    {
        char *res = ft_itoa(tests[i]);
        if (!res)
        {
            ok     = 0;
            failed = i;
            break;
        }
        /* Compare including terminating '\0' */
        if (ft_strncmp(res, expected[i], ft_strlen(expected[i]) + 1) != 0)
        {
            ok     = 0;
            failed = i;
        }
        /* Only free when malloc was used (not the INT_MIN literal) */
        if (tests[i] != -2147483648)
            free(res);
        if (!ok)
            break;
    }

    ft_putstr_fd("Test result: ", 1);
    ft_putchar_fd(ok ? '1' : '0', 1);
    if (ok)
        ft_putstr_fd(" (All edge cases true)\n", 1);
    else
    {
        ft_putstr_fd(" (Edge case #", 1);
        ft_putnbr_fd(failed, 1);
        ft_putstr_fd(" wrong)\n", 1);
    }
    return (ok);
}
