/* test_ft_strncmp.c */
#include "libft.h"

int main(void)
{
    struct {
        const char *s1;
        const char *s2;
        size_t      n;
        int         expected;
    } tests[] = {
        { "abc",  "abc",  3,    0 },
        { "abc",  "abd",  3,   -1 },   /* 'c' - 'd' = -1 */
        { "abc",  "abb",  3,    1 },   /* 'c' - 'b' = 1 */
        { "abc",  "abc",  0,    0 },   /* n = 0 should return 0 */
        { "",     "",     5,    0 },   /* both empty */
        { "a",    "",     1,    'a'  },/* 'a' - '\0' */
        { "",     "a",    1,   -'a'  },/* '\0' - 'a' */
        { "abc",  "abcd", 10,  -'d'  },/* '\0' - 'd' after 3 chars */
        { "test", "test", 10,   0 }
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;

    for (size_t i = 0; i < n_tests; ++i)
    {
        int res = ft_strncmp(tests[i].s1, tests[i].s2, tests[i].n);
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
