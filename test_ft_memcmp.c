/* test_ft_memcmp.c */
#include "libft.h"

int main(void)
{
    struct {
        const char *s1;
        const char *s2;
        size_t      n;
        int         expected;
    } tests[] = {
        { "abc",    "abc",    3,   0 },
        { "abc",    "abd",    2,   0 },  /* only compare 'a','b' */
        { "abc",    "abb",    3,   1 },  /* 'c'-'b' = 1 */
        { "abcd",   "abce",   4,  -1 },  /* 'd'-'e' = -1 */
        { "hello",  "hell",   5,   'o'  }, /* 'o'-'\0' = 'o' */
        { "hello",  "hellx",  5,  -('x'-'o') }, /* '\0'-'x' */
        { "",       "",       1,    0 },
        { "A",      "a",      1,   ('A'-'a') },
        { "12345",  "12335",  5,   1 },
        { "same",   "same",   0,    0 }   /* n=0 always returns 0 */
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    int    res;

    for (size_t i = 0; i < n_tests; ++i)
    {
        res = ft_memcmp(tests[i].s1, tests[i].s2, tests[i].n);
        if (res != tests[i].expected)
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
