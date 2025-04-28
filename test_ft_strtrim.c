/* test_ft_strtrim.c */
#include "libft.h"

int main(void)
{
    /* Test cases: s1,           set,      expected */
    const char *s1_tests[] = {
        NULL,
        "",
        "abcHelloabc",
        "Hello",
        "aaaa",
        "   trim   ",
        "!!Hi!!",
        "abHello",
        "Helloabc",
        "abc"
    };
    const char *set_tests[] = {
        "abc",     /* s1=NULL    → "" */
        "abc",     /* s1=""      → "" */
        "abc",     /* trim both  → "Hello" */
        "",        /* empty set  → original */
        "a",       /* full trim  → "" */
        " ",       /* trim spaces→ "trim" */
        "!",       /* trim !     → "Hi" */
        "abc",     /* trim start → "Hello" */
        "abc",     /* trim end   → "Hello" */
        NULL       /* NULL set   → original */
    };
    const char *expected[] = {
        "",
        "",
        "Hello",
        "Hello",
        "",
        "trim",
        "Hi",
        "Hello",
        "Hello",
        "abc"
    };
    size_t n_tests = sizeof(s1_tests) / sizeof(s1_tests[0]);
    int    ok      = 1;
    size_t failed  = 0;

    for (size_t i = 0; i < n_tests; ++i)
    {
        char *res = ft_strtrim(s1_tests[i], set_tests[i]);
        if (!res)
        {
            ok     = 0;
            failed = i;
            break;
        }
        /* compare including the terminating '\0' */
        if (ft_strncmp(res, expected[i], ft_strlen(expected[i]) + 1) != 0)
        {
            ok     = 0;
            failed = i;
            free(res);
            break;
        }
        free(res);
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
