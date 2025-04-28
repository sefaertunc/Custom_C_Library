/* test_ft_memchr.c */
#include "libft.h"

int main(void)
{
    struct {
        const void *s;
        int         c;
        size_t      n;
        int         expected;  /* offset or -1 if NULL */
    } tests[] = {
        { "abcdef",   'a', 6,  0 },  /* match at start */
        { "abcdef",   'd', 6,  3 },  /* match in middle */
        { "abcdef",   'f', 6,  5 },  /* match at end */
        { "abcdef",   'd', 3, -1 },  /* n too small, no match */
        { "abc\0xyz", '\0', 7,  3 },  /* match null byte within raw memory */
        { "hello",    'z', 5, -1 },  /* no such character */
        { "hello",    360,5,  0 }   /* 256 → (unsigned char)0, matches at offset 5 if n>5? here n=5 so no; expect -1 */
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;

    for (size_t i = 0; i < n_tests; ++i)
    {
        char *res = ft_memchr(tests[i].s, tests[i].c, tests[i].n);
        int   offset;
        if (res)
            offset = (int)((unsigned char *)res - (unsigned char *)tests[i].s);
        else
            offset = -1;
        if (offset != tests[i].expected)
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
