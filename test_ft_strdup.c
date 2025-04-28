/* test_ft_strdup.c */
#include "libft.h"

int main(void)
{
    const char *tests[] = {
        "",
        "Hello, World!",
        "42Vienna",
        "Test\0Hidden",   /* embedded null, only "Test" should be duplicated */
        "A",
        "This is a longer string to test strdup"
    };
    size_t n_tests = sizeof(tests) / sizeof(tests[0]);
    int    ok      = 1;
    size_t failed  = 0;

    for (size_t i = 0; i < n_tests; ++i)
    {
        const char *s   = tests[i];
        size_t      len = ft_strlen(s);
        char       *dup = ft_strdup(s);

        /* Check for NULL */
        if (!dup)
        {
            ok     = 0;
            failed = i;
            break;
        }
        /* Check content */
        if (ft_strncmp(dup, s, len + 1) != 0)
        {
            ok     = 0;
            failed = i;
            free(dup);
            break;
        }
        /* Check that it's a new allocation, not the same address */
        if (dup == s)
        {
            ok     = 0;
            failed = i;
            free(dup);
            break;
        }
        free(dup);
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
