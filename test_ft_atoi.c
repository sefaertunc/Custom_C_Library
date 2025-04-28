/* test_ft_atoi.c */
#include "libft.h"

int main(void)
{
    struct {
        char    *s;
        int      expected;
    } tests[] = {
        { "42",            42 },
        { "   -42",       -42 },
        { "\t\n\v 123",   123 },
        { "+7",             7 },
        { "-7",            -7 },
        { "--5",            0 },   /* two signs → 0 */
        { "+-5",            0 },   /* two signs → 0 */
        { "   ++5",         0 },   /* two signs → 0 */
        { "123abc",       123 },   /* stops at nondigit */
        { "abc123",         0 },   /* no leading digits */
        { "0",              0 },
        { "",               0 },   /* empty string */
        { "-",              0 },   /* lone sign */
        { "+",              0 },
        { "00042",         42 },   /* leading zeros */
        { "-00042",       -42 },   /* negative with leading zeros */
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    int    res;

    for (size_t i = 0; i < n_tests; ++i)
    {
        res = ft_atoi(tests[i].s);
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
