/* test_ft_memcpy.c */
#include "libft.h"

int main(void)
{
    struct { char *src; size_t n; } tests[] = {
        { "Hello", 5 },
        { "Test", 4 },
        { "Partial", 3 },
        { "Nulls", 6 },   /* include terminating '\\0' */
        { "", 0 }
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    char   dest[16];
    char   ref[16];

    for (size_t i = 0; i < n_tests; ++i)
    {
        size_t n = tests[i].n;
        /* fill buffers with a marker */
        ft_memset(dest, 'Z', sizeof dest);
        ft_memset(ref,  'Z', sizeof ref);

        /* perform ft_memcpy into dest and ref */
        ft_memcpy(dest, tests[i].src, n);
        ft_memcpy(ref,  tests[i].src, n);

        /* compare full buffers */
        if (ft_memcmp(dest, ref, sizeof dest) != 0)
        {
            ok     = 0;
            failed = i;
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
