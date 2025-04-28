/* test_ft_bzero.c */
#include "libft.h"

int main(void)
{
    size_t tests[]   = { 0, 1, 4 };
    size_t n_tests   = sizeof(tests) / sizeof(tests[0]);
    int    ok        = 1;
    size_t failed    = 0;
    char   buf[5];
    char   ref[5];

    for (size_t t = 0; t < n_tests; ++t)
    {
        size_t n = tests[t];
        /* fill both buffers with marker 'Z' (90) */
        ft_memset(buf, 'Z', 5);
        ft_memset(ref, 'Z', 5);
        /* call bzero on buf */
        ft_bzero(buf, n);
        /* prepare reference: zero first n bytes */
        ft_memset(ref, 0, n);
        /* compare entire buffer */
        if (ft_memcmp(buf, ref, 5) != 0)
        {
            ok     = 0;
            failed = t;
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
        ft_putnbr_fd(failed, 1);
        ft_putstr_fd(" wrong)\n", 1);
    }
    return (ok);
}
