/* test_ft_tolower.c */
#include "libft.h"

int main(void)
{
    int   tests[]    = { 'A', 'Z', 'a', '@', '[', '0', '\0', -1, 200 };
    int   expected[] = { 'a', 'z', 'a', '@', '[', '0', '\0', -1, 200 };
    size_t n_tests   = sizeof(tests) / sizeof(tests[0]);
    int    ok        = 1;
    size_t failed    = 0;

    for (size_t i = 0; i < n_tests; ++i)
    {
        if (ft_tolower(tests[i]) != expected[i])
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
