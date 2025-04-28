/* test_ft_strchr.c */
#include "libft.h"

int main(void)
{
    struct {
        const char *s;
        int         c;
        int         expected; /* offset in s, or -1 for NULL */
    } tests[] = {
        { "Hello",       'H',  0 },
        { "Hello",       'e',  1 },
        { "Hello",       'l',  2 },
        { "Hello",       'o',  4 },
        { "Hello",       'x', -1 },
        { "Hello",       '\0', 5 },
        { "",            '\0', 0 },
        { "",            'A', -1 },
        { "banana",      'a',  1 },
        { "banana",      'n',  2 }
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;

    for (size_t i = 0; i < n_tests; ++i)
    {
        char *res = ft_strchr(tests[i].s, tests[i].c);
        int   offset;
        if (res)
            offset = (int)(res - tests[i].s);
        else
            offset = -1;
        if (offset != tests[i].expected)
        {
            ok      = 0;
            failed  = i;
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
