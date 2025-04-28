/* test_ft_strjoin.c */
#include "libft.h"

int main(void)
{
    const char *s1_tests[] = {
        "",             /* both empty */
        "",             /* first empty */
        "Hello",        /* normal + empty */
        "Libft",        /* normal + normal */
        "Foo",          /* special chars */
        "LongString",   /* longer strings */
        "123",          /* numeric strings */
        "Edge",         /* edge of memory */
    };
    const char *s2_tests[] = {
        "", 
        "World",
        "", 
        " Library",
        "!@#", 
        "Testing123",
        "456",
        "Case"
    };
    const char *expected[] = {
        "",              /* "" + "" */
        "World",         /* "" + "World" */
        "Hello",         /* "Hello" + "" */
        "Libft Library", /* "Libft" + " Library" */
        "Foo!@#",        /* "Foo" + "!@#" */
        "LongStringTesting123", /* "LongString" + "Testing123" */
        "123456",        /* "123" + "456" */
        "EdgeCase"       /* "Edge" + "Case" */
    };
    size_t n_tests = sizeof(s1_tests) / sizeof(s1_tests[0]);
    int    ok      = 1;
    size_t failed  = 0;
    char   *res;

    for (size_t i = 0; i < n_tests; ++i)
    {
        res = ft_strjoin(s1_tests[i], s2_tests[i]);
        if (!res)
        {
            ok     = 0;
            failed = i;
            break;
        }
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
