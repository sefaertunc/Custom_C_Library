/* test_ft_memset.c */
#include "libft.h"

int main(void)
{
    struct { int c; size_t n; } tests[] = {
        { 'A', 5 },
        { 0,   3 },
        { -1,  4 }, /* -1 → (unsigned char)255 */
        { 'x', 0 }
    };
    size_t   n_tests = sizeof(tests) / sizeof(tests[0]);
    int      ok      = 1;
    size_t   failed  = 0;
    char     buf1[10];
    char     buf2[10];

    for (size_t i = 0; i < n_tests; ++i)
    {
        /* initialize both buffers with a marker */
        ft_memset(buf1, 'Z', tests[i].n + 2);
        ft_memset(buf2, 'Z', tests[i].n + 2);

        /* call your memset */
        ft_memset(buf1, tests[i].c, tests[i].n);
        /* prepare expected */
        ft_memset(buf2, tests[i].c, tests[i].n);

        /* compare only the first n bytes */
        if (ft_memcmp(buf1, buf2, tests[i].n) != 0)
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
